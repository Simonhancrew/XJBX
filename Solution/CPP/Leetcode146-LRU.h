#include <unordered_map>
using namespace std;

//一个双向链表，链表node存key，value
class Node{
public:
    int key,value;
    Node* prev;
    Node* next;
    Node():key(0),value(0),prev(nullptr),next(nullptr){}
    Node(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        this -> capacity = capacity;
        size = 0;
        head->next = tail;//类似于dummy节点，因为头尾节点经常被修改，去掉特判
        tail->prev = head;
    }   
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* node = cache[key];
        moveTohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            Node* node = new Node(key,value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > capacity){
                Node* rm = removeTail();
                cache.erase(rm->key);
                delete rm;
                --size;
            }
        }else{
            Node* node = cache[key];
            node->value = value;
            moveTohead(node);
        }
    }

    void moveTohead(Node* node){
        remove(node);
        addToHead(node);
    }
    
    void remove(Node* node){
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }

    void addToHead(Node* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    Node* removeTail(){
        Node* node = tail->prev;
        tail->prev = node->prev;
        node->prev->next = tail;
        return node;
    }
private:
    unordered_map<int,Node*> cache;//hash去判断是否存在key
    Node* head;
    Node* tail;//虚拟头节点
    int size;
    int capacity;
};