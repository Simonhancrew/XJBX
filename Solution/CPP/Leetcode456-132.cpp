#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        vector<int> mini(nums.size(),0);
        mini[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            mini[i] = min(mini[i-1],nums[i]);
        }
        stack<int> stk;
        //多少带点贪心，左边最小，右边单调栈
        for(int j= nums.size()-1;j>=0;j--){
            if(nums[j]>mini[j]){
                while(!stk.empty() && stk.top()<=mini[j]){
                    stk.pop();
                }
                if(!stk.empty() && stk.top()<nums[j]){
                    return true;
                }
                stk.push(nums[j]);
            }
            
        }
        return false;
    }
};

//枚举ai,判断ai的后面是否存在ak存在aj,符合要求
//一种很优美的解法，记录了2，2右边一定有一个3，枚举的每一个数，如果小于2，那就找到了1
//利用单调栈去记录3（可以理解成不合格的2）
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }
        int two = INT_MIN;
        stack<int> stk;
        for(int i = n-1;i >=0;i--){
            if(nums[i] < two) return true;
            while(stk.size() && nums[i] > stk.top()){
                two = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> c = {1,2,3,4};
    Solution solve;
    bool b = solve.find132pattern(c);
    cout << b <<endl;
    return 0;
}