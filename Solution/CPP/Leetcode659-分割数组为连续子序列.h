#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
//从左往右遍历序列
//一个哈希表，key = 当前值结束，value = 以当前值结束的序列长度的集合
//因为以这个值结束的序列可能不止一个，所以维护一个最小堆，这样结束时只要堆顶的元素小于3就可以直接返回false
//遍历时，先创建x的键，然后找有没有以x-1结尾的序列，题意要让所有序列都大于3
//我们就让前一个序列集合中的最短+1
//如果此时前一个序列集合为空了，我们也要销毁它
//最后遍历存在的堆顶，只要有小于3的就直接返回false
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        for(auto &num:nums){
            //先创建空间，如果存在，说明又重复，后续又新一个序列push 1
            if(mp.find(num) == mp.end()){
                mp[num]  = priority_queue<int,vector<int>,greater<int>> (); 
            }
            //存在以num - 1结尾的序列集合
            if(mp.find(num - 1) != mp.end()){
                //找打最短的长度
                int len = mp[num - 1].top();
                //此时这个序列要用新的num结尾，进入新的序列集合
                mp[num - 1].pop();
                //旧序列集合空了得话抹除
                if(mp[num - 1].empty()){
                    mp.erase(num - 1);
                }
                //新序列集合更新
                mp[num].push(len + 1);
            }else{
                mp[num].push(1);
            }
        }
        for(auto i = mp.begin();i != mp.end();++i){
            auto que = i->second;
            if(que.top() < 3){
                return false;
            }
        }
        return true;
    }
};

//贪心的思路，尽量不要创建新的短序列
//使用两个哈希表，第一个哈希表存储数组中的每个数字的剩余次数，第二个哈希表存储数组中的每个数字作为结尾的子序列的数量。
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        //初始次数
        for (auto& x : nums) {
            int count = countMap[x] + 1;
            countMap[x] = count;
        }
       
        for (auto& x : nums) {
            int count = countMap[x];
            //当一个数字的count大于0才考虑他是否属于一个序列
            if (count > 0) {
                //是否存在以x-1结尾的序列
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0) {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                } else {
                    //否则需要创建新序列
                    //之后的两个值一定要在新序列中最后结果才true
                    //所以他一定要存在
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};