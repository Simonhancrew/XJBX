//
// Created by han on 2020/9/2.
//

#ifndef FUNDEMENTALADT_VECTOR_H
#define FUNDEMENTALADT_VECTOR_H
typedef int Rank;//
#define DEFAULT_CAPACITY 3 //init start capacity
template <typename T> class Vector {
protected:
    Rank _size; int _capacity; T *_elem; //规模、容量、数据区
    void copyFrom(T const *A, Rank lo, Rank hi);//复制数组区
    void expand();//空间不足扩容
    void shrink();//装填不足收缩
    bool bubble(Rank lo,Rank hi);//扫描交换
    void bubbleSort(Rank lo,Rank hi);//冒泡排序
    Rank max(Rank lo,Rank hi);//选取最大的元素
    void selectionSort(Rank lo,Rank hi);//选择排序
    void merge(Rank lo,Rank mi,Rank hi);//归并
    void mergeSort(Rank lo,Rank hi);//归并排序
    void heapSort(Rank lo,Rank hi);//堆排
    void quickSort(Rank lo, Rank hi);//快排
    void shellSort(Rank lo,Rank hi);//希尔排序
public:
    //构造函数
    Vector(int c = DEFAULT_CAPACITY,int s = 0,T v = 0){
        //容量为c,规模为s，所有初始元素为v
        _elem = new T[_capacity = c];
        //s<=c
        for(_size = 0;_size<s;_elem[_size++] = v) ;
    }
    //复制一个数组
    Vector(T const *A,Rank n){copyFrom(A,0,n);}
    //区间复制数组
    Vector(T const* A,Rank lo,Rank hi){copyFrom(A,lo,hi);}
    //vector的整体复制
    Vector(Vector<T> const &V){copyFrom(V._elem,0,V._size);}
    //vector的区间复制
    Vector(Vector<T> const &V,Rank lo,Rank hi){copyFrom(V._elem,lo,hi);}
    //析构函数,释放数据区
    ~Vector(){delete []_elem;}
    //只读接口
    Rank size() const{return _size;}
    bool empty() const{return !_size;}
    Rank find(T const &e) const {return find(e,0,_size);}//整体查找
    Rank find(T const &e,Rank lo,Rank hi) const;//区间查找
    Rank search(T const &e) const{return (0 >= _size)?-1:search(e,0,_size);};//有序的区间查找
    Rank search(T const &e,Rank lo,Rank hi) const;
    //可写接口和访问
    T& operator[](Rank r);//重载下标运算符
    const T& operator[](Rank r) const;//仅做右值
    Vector<T> &operator = (Vector<T> const&);//重载赋值运算符，直接克隆一整个向量
    T remove(Rank r);//删除r位置的数
    int remove(Rank lo,Rank hi);//区间删除，左闭右开
    Rank insert(Rank r,T const& e);//插入元素
    Rank insert(T const &e){return insert(_size,e);}//等同于push_back
    void sort(){sort(0,_size);}
    void sort(Rank lo,Rank hi);//整体排序
    void unsort(Rank lo,Rank hi);//整体扰乱，knuth-shuffle
    void unsort(){unsort(0,_size);}
    int deduplicate();//无序去重
    int uniquify();//有序去重
    //遍历
    void traverse(void(*)(T&));//遍历，用函数指针，只读或者局部修改
    template <typename VST> void traverse ( VST& ); //遍历（使用函数对象，可全局性修改）
};
#endif //FUNDEMENTALADT_VECTOR_H