#include <string>
using namespace std;
const int N = 1e6 + 10;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(hash,0,sizeof(hash));
    }
    
    void add(int key) {
        ++hash[key];
    }
    
    void remove(int key) {
        hash[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key]==0?false:true;
    }
private:
    //不在全局变量的花是不为0的
    int hash[N];
};


//动态分配
#include <vector>
#include <list>
class MyHashSetStl{
public:
    vector<list<int>> dt;
    static const int base = 769;
    static int hash(int x){
        return x % base;
    }
public:

    MyHashSetStl():dt(base){}
    
    void add(int key){
        int h = hash(key);
        for(auto it = dt[h].begin();it != dt[h].end();it++){
            if((*it) == key){
                return;
            }
        }
        dt[h].push_back(key);
    }

    void remove(int key){
        int h = hash(key);
        for(auto it = dt[h].begin();it != dt[h].end();it++){
            if((*it) == key){
                dt[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key){
        int h = hash(key);
        for(auto it = dt[h].begin();it != dt[h].end();it++){
            if((*it) == key){
                return true;
            }
        }
        return false;
    }
};