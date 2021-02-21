#include <vector>
#include <set>
using namespace std;
//做一个有序集合，只要最大最小的差大于limit就一直删除数组中的左端元素
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> in;
        int n = nums.size();
        int start = 0;
        int ret = 0;
        for(int end = 0;end < n;++end){
            in.insert(nums[end]);
            while(*in.rbegin() - *in.begin() > limit){
                in.erase(in.find(nums[start++]));
            }
            ret = max(ret,end - start + 1);
        }   
        return ret;
    }   
};

//做两个单点队列，当前窗口的最大最小值就在这两个队列头部
#include <deque>
class Solution{
public:
    int longestSubarray(vector<int> &nums,int limit){
        deque<int> maxlist,minlist;
        int n = nums.size();
        int left = 0,ret = 0;
        for(int right = 0;right < n;right++){
            while(!maxlist.empty() && maxlist.back() < nums[right]){
                maxlist.pop_back();
            }
            while(!minlist.empty() && minlist.back() > nums[right]){
                minlist.pop_back();
            }
            maxlist.push_back(nums[right]);
            minlist.push_back(nums[right]);
            while(!maxlist.empty() && !minlist.empty() && maxlist.front() - minlist.front() > limit){
                if(nums[left] == minlist.front()){
                    minlist.pop_front();
                }
                if(nums[left] == maxlist.front()){
                    maxlist.pop_front();
                }
                left++;
            } 
            ret = max(ret,right - left + 1);
        }
        return ret;
    }
};