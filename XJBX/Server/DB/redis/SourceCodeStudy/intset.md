## 整数集合

IntSet是集合键的底层实现之一，如果一个集合只包含数值元素的话，且数值元素不多，redis就会用整数集合作为集合键的底层实现。

### 实现

```
typedef struct intset {
    
    // 编码方式
    uint32_t encoding;

    // 集合包含的元素数量
    uint32_t length;

    // 保存元素的数组
    int8_t contents[];

} intset;
```

contents虽然是int8的，但是实际保存数的大小要看encoding的方式，然后根据升级规则，如果新加入一个更大的数值类型，contents中的全部数值要升级为更大的数值类型。

访问数值之类的功能是利用到了强转和索引的

```
/* Return the value at pos, given an encoding. 
 *
 * 根据给定的编码方式 enc ，返回集合的底层数组在 pos 索引上的元素。
 *
 * T = O(1)
 */
static int64_t _intsetGetEncoded(intset *is, int pos, uint8_t enc) {
    int64_t v64;
    int32_t v32;
    int16_t v16;

    // ((ENCODING*)is->contents) 首先将数组转换回被编码的类型
    // 然后 ((ENCODING*)is->contents)+pos 计算出元素在数组中的正确位置
    // 之后 member(&vEnc, ..., sizeof(vEnc)) 再从数组中拷贝出正确数量的字节
    // 如果有需要的话， memrevEncifbe(&vEnc) 会对拷贝出的字节进行大小端转换
    // 最后将值返回
    if (enc == INTSET_ENC_INT64) {
        memcpy(&v64,((int64_t*)is->contents)+pos,sizeof(v64));
        memrev64ifbe(&v64);
        return v64;
    } else if (enc == INTSET_ENC_INT32) {
        memcpy(&v32,((int32_t*)is->contents)+pos,sizeof(v32));
        memrev32ifbe(&v32);
        return v32;
    } else {
        memcpy(&v16,((int16_t*)is->contents)+pos,sizeof(v16));
        memrev16ifbe(&v16);
        return v16;
    }
}



/* Set the value at pos, using the configured encoding. 
 *
 * 根据集合的编码方式，将底层数组在 pos 位置上的值设为 value 。
 *
 * T = O(1)
 */
static void _intsetSet(intset *is, int pos, int64_t value) {

    // 取出集合的编码方式
    uint32_t encoding = intrev32ifbe(is->encoding);

    // 根据编码 ((Enc_t*)is->contents) 将数组转换回正确的类型
    // 然后 ((Enc_t*)is->contents)[pos] 定位到数组索引上
    // 接着 ((Enc_t*)is->contents)[pos] = value 将值赋给数组
    // 最后， ((Enc_t*)is->contents)+pos 定位到刚刚设置的新值上 
    // 如果有需要的话， memrevEncifbe 将对值进行大小端转换
    if (encoding == INTSET_ENC_INT64) {
        ((int64_t*)is->contents)[pos] = value;
        memrev64ifbe(((int64_t*)is->contents)+pos);
    } else if (encoding == INTSET_ENC_INT32) {
        ((int32_t*)is->contents)[pos] = value;
        memrev32ifbe(((int32_t*)is->contents)+pos);
    } else {
        ((int16_t*)is->contents)[pos] = value;
        memrev16ifbe(((int16_t*)is->contents)+pos);
    }
}
```

然后看到查找这里用了一个二分

```

/* Search for the position of "value".
 * 
 * 在集合 is 的底层数组中查找值 value 所在的索引。
 *
 * Return 1 when the value was found and 
 * sets "pos" to the position of the value within the intset. 
 *
 * 成功找到 value 时，函数返回 1 ，并将 *pos 的值设为 value 所在的索引。
 *
 * Return 0 when the value is not present in the intset 
 * and sets "pos" to the position where "value" can be inserted. 
 *
 * 当在数组中没找到 value 时，返回 0 。
 * 并将 *pos 的值设为 value 可以插入到数组中的位置。
 *
 * T = O(log N)
 */
static uint8_t intsetSearch(intset *is, int64_t value, uint32_t *pos) {
    int min = 0, max = intrev32ifbe(is->length)-1, mid = -1;
    int64_t cur = -1;

    /* The value can never be found when the set is empty */
    // 处理 is 为空时的情况
    if (intrev32ifbe(is->length) == 0) {
        if (pos) *pos = 0;
        return 0;
    } else {
        /* Check for the case where we know we cannot find the value,
         * but do know the insert position. */
        // 因为底层数组是有序的，如果 value 比数组中最后一个值都要大
        // 那么 value 肯定不存在于集合中，
        // 并且应该将 value 添加到底层数组的最末端
        if (value > _intsetGet(is,intrev32ifbe(is->length)-1)) {
            if (pos) *pos = intrev32ifbe(is->length);
            return 0;
        // 因为底层数组是有序的，如果 value 比数组中最前一个值都要小
        // 那么 value 肯定不存在于集合中，
        // 并且应该将它添加到底层数组的最前端
        } else if (value < _intsetGet(is,0)) {
            if (pos) *pos = 0;
            return 0;
        }
    }

    // 在有序数组中进行二分查找
    // T = O(log N)
    while(max >= min) {
        mid = (min+max)/2;
        cur = _intsetGet(is,mid);
        if (value > cur) {
            min = mid+1;
        } else if (value < cur) {
            max = mid-1;
        } else {
            break;
        }
    }

    // 检查是否已经找到了 value
    if (value == cur) {
        if (pos) *pos = mid;
        return 1;
    } else {
        if (pos) *pos = min;
        return 0;
    }
}
```



### 升级

有三种类型

```
/* Note that these encodings are ordered, so:
 * INTSET_ENC_INT16 < INTSET_ENC_INT32 < INTSET_ENC_INT64. */
/*
 * intset 的编码方式
 */
#define INTSET_ENC_INT16 (sizeof(int16_t))
#define INTSET_ENC_INT32 (sizeof(int32_t))
#define INTSET_ENC_INT64 (sizeof(int64_t))
```

每次升级都可能带来类型转换和位置迁移，所以是O（n）的

### 升级的好处

1. 灵活
2. 节约内存（避免全部用大整形表示）

### 降级

整数集合不支持降级

### 总结

整数集合带来了灵活性，能够节约内存，但不支持降级。

