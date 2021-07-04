#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> st(n + 1);
        vector<int> res;
        for(auto num:nums){
            st[num]++;
            if(st[num] > 1) res.push_back(num); 
        }
        for(int i = 1;i <= n;i++){
            if(st[i] == 0) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};