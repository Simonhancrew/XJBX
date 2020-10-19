#include <vector>
#include <stack>
using namespace std;
//环数组的处理方法一般是假装这个数组翻倍了
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> s;
        int n = nums.size();
        for(int i = 2*n-1;i>=0;--i){
            //索引求模
            while(!s.empty() && nums[i%n] >= s.top()){
                s.pop();
            }
            res[i%n] = s.empty()?-1:s.top();
            s.push(nums[i%n]);
        }
        return res;
    }
};