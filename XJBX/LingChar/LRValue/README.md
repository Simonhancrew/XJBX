## 左值和右值的理解

### 1 什么是左值和右值

简单的描述，左值就是出现在等号左边，有名称的值。右值出现在等号的右边，无法取地址（左值可以取地址）。

```
int a = 5;
int &b = a;
```

```
struct A{
	A(int a = 0){}
	int a;
};
A a = A();
//a可以取地址，A()是个临时值，无法取地址
```

### 2 什么是左值引用，右值引用

引用的表面意思是别名，通过修改引用的值就可以修改变量的值，传参可以避免拷贝。

#### 2.1 左值引用

```
int a = 5;
int &b = a;
int &c = 5;//wrong 左值引用指向了右值
```

右值引用没有地址，无法修改，所以无法使用左值引用指向右值

但是const左值引用是可以指向右值的

```
const int &b = 5;//可以过compile
```

const的左值引用无法修改指向值,没有这种const &的话push_back常量就无法过编译了

```
void push_back (const value_type& val);
```

#### 2.2 右值引用

右值引用的标志是&&，专门为了右值而生，但是比较独特的是如果右值引用出现在等号的左边，且有申明名字的话，那他其实是个左值。

```
int &&a = 5; //ok
int ref = 5;
int &&b = res;//wrong 无法指向右值
a += 1;//右值引用可以修改右值
```

### 2.3 std::move

右值引用可以通过std::move指向左值，std::move(a)可以将a转化位右值，可以被右值引用所指

```
int a = 5;
int &&ref = std::move(a);
```

此处，a依然是有值的，并不和移动赋值函数一样，失去了值。他唯一的功能就是把左值强转成为右值。所以淡出的std::move并不会给你的代码带来速度和内存上的提升

另外，**被声明出来的左、右值引用都是左值**。 因为被声明出的左右值引用是有地址的，也位于等号左边。

```
// 形参是个右值引用
void change(int&& right_value) {
    right_value = 8;
}
 
int main() {
    int a = 5; // a是个左值
    int &ref_a_left = a; // ref_a_left是个左值引用
    int &&ref_a_right = std::move(a); // ref_a_right是个右值引用
 
    change(a); // 编译不过，a是左值，change参数要求右值
    change(ref_a_left); // 编译不过，左值引用ref_a_left本身也是个左值
    change(ref_a_right); // 编译不过，右值引用ref_a_right本身也是个左值
     
    change(std::move(a)); // 编译通过
    change(std::move(ref_a_right)); // 编译通过
    change(std::move(ref_a_left)); // 编译通过
 
    change(5); // 当然可以直接接右值，编译通过
     
    cout << &a << ' ';
    cout << &ref_a_left << ' ';
    cout << &ref_a_right;
    // 打印这三个左值的地址，都是一样的
}
```

**右值引用既可以是左值也可以是右值，如果有名称则为左值，否则是右值**。

所以得到的总结就是

1. **从性能上讲，左右值引用没有区别，传参使用左右值引用都可以避免拷贝。**
2. **右值引用可以直接指向右值，也可以通过std::move指向左值；而左值引用只能指向左值(const左值引用也能指向右值)。**
3. **作为函数形参时，右值引用更灵活。虽然const左值引用也可以做到左右值都接受，但它无法修改，有一定局限性。**

```
void f(const int& n) {
    n += 1; // 编译失败，const左值引用不能修改指向变量
}

void f2(int && n) {
    n += 1; // ok
}

int main() {
    f(5);
    f2(5);
}
```

### 3 右值引用的场景，move的应用

#### 3.1 实现移动语义

拷贝构造函数，就算传参是引用的，也还是会在函数的内部重开内存复制原来空间上的内容

```
class Array {
public:
    Array(int size) : size_(size) {
        data = new int[size_];
    }
     
    // 深拷贝构造
    Array(const Array& temp_array) {
        size_ = temp_array.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i ++) {
            data_[i] = temp_array.data_[i];
        }
    }
     
    // 深拷贝赋值
    Array& operator=(const Array& temp_array) {
        delete[] data_;
 
        size_ = temp_array.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i ++) {
            data_[i] = temp_array.data_[i];
        }
    }
 
    ~Array() {
        delete[] data_;
    }
 
public:
    int *data_;
    int size_;
};
```

那有没有办法，让原来的对象，移动到我们新构造的对象中去，且移动完之后被拷贝的对象就失效了呢？这个时候你可能会想到const&,之后提前质空原来对象的空间，但是。const&是无法改变指向对象的，这是const限定死的

那么如果使用int &&呢

```
  Array(Array&& temp_array) {
        data_ = temp_array.data_;
        size_ = temp_array.size_;
        // 为防止temp_array析构时delete data，提前置空其data_      
        temp_array.data_ = nullptr;
    }
```

好像可以实现了啊，但是要注意怎么使用呢？如果传进来的是个左值，他还是会使用默认的拷贝构造函数，这时候就需要move了

```
int main(){
    Array a;
 
    // 做一些操作
    .....
     
    // 左值a，用std::move转化为右值
    Array b(std::move(a));
}
```

这样利用move和右值，就可以显著的提高性能了



总的来说，move只是一个类型强转，单独的使用并无性能优化的意义。但是，在我们自己实现的类中，如果实现了移动语义的话，就可以避免拷贝，充分利用右值引用和move的特性去做一些性能的优化。