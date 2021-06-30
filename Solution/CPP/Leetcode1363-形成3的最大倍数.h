#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// sum是3的倍数，不是的话，余1删除一个最小的除3余1的或者2个除3余2的
// 遍历一数组，记录和，记录每个数多少，记录余数总数
// 从小到大遍历就行了，每次记录还有多少个要删除的，和要删除的是余几的


class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        vector<int> cnt(10),mod(3);
        for(auto digit:digits){
            cnt[digit]++;
            mod[digit % 3]++;
            sum += digit;
        }
        int remove = 0,rest = 0;
        if(sum % 3 == 1){
            if(mod[1] >= 1){
                rest = 1;
                remove = 1;
            }else{
                rest = 2;
                remove = 2;
            }
        }else if(sum % 3 == 2){
            if(mod[2] >= 1){
                rest = 1;
                remove = 2;
            }else{
                rest = 2;
                remove = 1;
            }
        }
        string ans;
        for(int i = 0;i <= 9;i++){
            for(int j = 0;j < cnt[i];j++){
                if(rest && remove == i % 3){
                    --rest;
                }else{
                    ans += ('0' + i);
                }
            }
        }
        if(ans.size() && ans.back() == '0'){
            ans = "0";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};