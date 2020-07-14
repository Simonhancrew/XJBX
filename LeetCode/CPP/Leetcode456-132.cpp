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

int main(){
    vector<int> c = {1,2,3,4};
    Solution solve;
    bool b = solve.find132pattern(c);
    cout << b <<endl;
    return 0;
}