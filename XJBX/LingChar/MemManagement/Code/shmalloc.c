#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

// 2 存一个node
struct block_meta{
    size_t size;
    struct block_meta* next;//单链表实现
    int free;//有没有人用啊
    int magic;
};

#define META_SIZE sizeof(struct block_meta) 

//单链表的头
void *global_base = NULL;//dummy节点，leetcode链表头节点经常变动需要的小技巧。

//3 使用内存池的话，就遍历一下链表找到能用的呗
struct block_meta* find_free_block(struct block_meta** last,size_t size){
    struct block_meta *current = global_base;
    while(current && !(current->free && current->size >= size)){
        *last = current;
        current = current->next;
    }
    return current;
}

// 4 不够用就分配一下咯
struct block_meta *request_space(struct block_meta *last,size_t size){
    struct block_meta *block;
    block = sbrk(0);
    void *request == sbrk(size + META_SIZE);
    assert((void*)block == request);
    if(request == (void*) -1){
        return NULL;//fail
    }
    if(last){//第一次请求的时候表头是个NULLL
        last->next = block;
    }
    block->size = size;
    block->next = NULL;
    block->free = 0;
    block->magic = 0x12345678;
    return block;
}


//5 重新写一下现在的malloc
void *secondmalloc(size_t size){
    struct block_meta* block;
    if(size <= 0) return NULL;
    if(!global_base){//第一次调用哈
        block = request_space(size);
        if(!block){
            return NULL;
        }
        global_base = block;
    }else{
        struct block_meta* last = global_base;
        block = find_free_block(&last,size);
        if(!block){//找不到合乎要求的block
            block = request_space(last,size);
            if(!block){
                return NULL;
            }
        }else{
            block->free = 0;
            block->magic = 0x77777777;
        }
    }
    return (block + 1);//堆是往地址矮的地方张的，我们要的是完整的block空间
}

// 6 free的思路

struct block_meta* get_block_ptr(void *ptr){
    return (struct block_meta*)ptr - 1;
}

// 你不应该free两次吧
void free(void *ptr){
    //防卫
    if(!ptr){
        return;
    }
    struct block_meta* block_ptr = get_block_ptr(prt)l;
    assert(block_ptr -> free == 0);
    assert(block_ptr -> magic == 0x7777777 || block_ptr->magic == 0x12345678);
    block_ptr -> free = 1;
    block_ptr -> magic = 0x55555555;
}


// 7 realloc
void *realloc(void* ptr,size_t size){
    if(!ptr){//NULL的时候就是分配空间
        return secondmalloc(size);
    }
    struct block_meta* block_ptr = get_block_ptr(ptr);
    if(block_ptr->size >= size){
        //足够大，啥也不干。
        return prt;
    }
    void *new_ptr;
    new_ptr = secondmalloc(size);
    if(!new_ptr){
        return NULL;
    }
    memccpy(new_ptr,ptr,block_ptr->size);
    free(ptr);
    return new_ptr;
}

// 8 calloc,清空啦
void *calloc(size_t nelem,size_t elsize){
    size_t size = nelem * elsize;
    void *ptr = secondmalloc(size);
    memset(prt,0,sizeof ptr);
    return prt;
}




//1 最简单的版本malloc,该版本在错误，malloc(0)的时候，应该返回一个东西，让free可以释放。
//然后频繁的内核态，比较损失性能
//最后，free的时候怎么知道他的需要释放的大小呢？多家一个标记位？储存一下大小信息，
// ok，假如我释放了，这一段正好在堆的中间，brk没办法跟踪到这一段，这不是就废了一大段的空间吗》？
// 上面的内存空间做一个offset？很复杂的
// 内存池啊，用了不还，之后要用重新调用。
void *firstmalloc(size_t size){
    void *p = sbrk(0);//返回当前堆开始位置
    void request = sbrk(size);//heap增大size，返回之前的top
    if(request == (void*) -1){
        return NULL;//sbrk fails
    }else{
        assert(p == request);//不是线程安全的,hh
        return p;
    }
}


void free(void *ptr);