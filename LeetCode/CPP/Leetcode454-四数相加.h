#include <vector>
#include <unordered_map>
using namespace std;
//分组哈希
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> count1;
        for(const auto &a : A){
            for(const auto& b:B){
                ++count1[a+b];
            }  
        }
        int ret = 0;
        for(const auto &c:C){
            for(const auto& d:D){
                if(count1.count(-c-d)){
                    ret += count1[-c-d];
                }
            }
        }
        return ret;
    }
};