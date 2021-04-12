#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//排序，去除先导零
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),[](int lhs,int rhs){
            string l = to_string(lhs);
            string r = to_string(rhs);
            return l + r > r + l;
        });
        for(auto &num:nums){
            res += to_string(num);
        }
        for(int i = 0;i < res.size();i++){
            if(res[i] != '0'){
                return res.substr(i,res.size());
            }
        }
        return res.substr(res.size() - 1);
    }
};