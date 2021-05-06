## 智能指针（shared_ptr）

### 1 传统指针的存在什么问题

C++的特点之一就是很相信程序员本身的能力，也因为这个原因在指针的问题上如果你没有处理好，会带来很多的问题

你在堆上创建了一个对象的时候，系统就会把这个对象的生命周期交由你来管理，用完之后不想栈区的会自动销毁，这个对象的生命需要由你来手动结束。由此引出两个问题 ，什么时候释放？在哪里释放？

这两个问题没有处理好的话就会导致内存泄露或者程序的崩溃。

```
//泄露
{
	string *s1 = new string("hello");
	string *s2 = new string("hc 我是你爸爸");
}//离开段，没有释放，内存泄漏 

{
	string *s1 = new string("haah");
	delete s1;
	
	
	//delete again
	delete S1;
}//重复的delete会引发panic导致程序崩溃
```

在这种代码量小，一个作用域的时候，这种问题很容易被看出来，但是当项目更大的时候，逻辑更为复杂的情况下，这种问题是很难被排查出来的（某个作用域的对象可能要到另外一份代码的逻辑中释放）。

### 2  智能指针如何解决这个问题的

问题的核心在于引用计数

1. 从堆上申请一个资源的时候就创建一个智能指针，这个指针指向这个资源，这个智能指针的内部会存在一个引用计数器，所有后来的指向该资源的对象都共享这个计数器，引用计数唯一
2. 后续的赋值给其他智能指针的时候，共享计数器的值会++
3. 删除一个后续的智能指针，计数器会--
4. 删除最初的智能指针的时候，计数器归零，之后释放资源

### 3 如何实现一个shared_ptr

```
template<class T>
class SharedPointer{
public:
	SharedPointer() :refCount(nullptr), pointer(nullptr){}
	SharedPointer(T* adoptTarget) :refCount(nullptr), pointer(adoptTarget)
    {
        addReference();
    }
    
     SharedPointer(const SharedPointer<T>& copy)
        :refCount(copy.refCount), pointer(copy.pointer)
    {
        addReference();
    }
    
    virtual ~SharedPointer()
    {
        removeReference();
    }
    
    //左值，被赋值的时候不再指向之前的值，要先减少之前的引用计数，然后指向新的资源，++新对象的计数
    SharedPointer<T>& operator=(const SharedPointer<T>& that)
    {
        if (this != &that)
        {
            removeReference();
            this->pointer = that.pointer;
            this->refCount = that.refCount;
            addReference();
        }
        return *this;
    }
    bool operator==(const SharedPointer<T>& other)
    {
        return pointer == other.pointer;
    }
    
    bool operator!=(const SharedPointer<T>& other)
    {
        return !operator==(other);
    }
    
     T& operator*() const
    {
        return pointer;
    }
    //成员调用
    T* operator->() const
    {
        return pointer;
    }
    //获取引用计数值
    int GetReferenceCount() const
    {
        if (refCount)
        {
            return *refCount;
        } 
        else
        {
            return -1;
        }
    }
protected:
	void addReference()
    {
        if (refCount)
        {
            (*refCount)++;
        }
        else
        {
            refCount = new int(0);
            refCount = 1;
        }
    }
    
     void removeReference()
    {
        if (refCount)
        {
            (*refCount)--;
            if (*refCount == 0)
            {
                delete refCount;
                delete pointer;
                refCount = 0;
                pointer = 0;
            }
        }
    }
private:
	int *refCount;
	T *pointer;

};
```

### 4 关于unique，weak的ptr和注意事项

> todo