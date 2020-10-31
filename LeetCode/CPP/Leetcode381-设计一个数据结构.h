#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size()-1);
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //没有这个值
        if(idx.find(val) == idx.end()){
            return false;
        }
        //交换该元素和最后一个元素
        int i = *idx[val].begin();//找到第一个下标
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size()-1);
        //不是下标位置才能将原来nums最后一个数的下标更改
        if(i < nums.size()-1){
            idx[nums[i]].insert(i);
        }
        if(idx[val].size() == 0){
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    //储存所有的数字
    vector<int> nums;
    //映射值和出现的下标位置
    unordered_map<int,unordered_set<int>> idx;
};