## 二分搜索模板解读

二分的模板很简单，这里记录一下check函数判断找到的是上界还是下界的问题

首先拿出二分模板

```
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

注意l + r >> 1是下取整的，所以实际更新的时候，如果更新的是l，需要考虑边界的问题，否则就会死循环，比如

```
l = 0,r = 1
l = mid = (l + r) >> 1 
```

此时l还是0，完全死循环了。改成`l + r + 1 >> 1`就没有问题了。

另外还有上下界的判断问题，这里记录一下怎么找上界

```
if(num[mid] <= target) l = mid;
```

这里每次等于的时候边界也会更新，一直到不能更新的时候找到了恰好找到了target的右边界，l == r,更新结束。简而言之就是左边界会一直往右边缩小。

同理，下界就是.满足条件的时候右边界一直往下缩小。

```
if(num[mid] >= target) r = mid
```

