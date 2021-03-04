#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int m = strs[0].size();
        int n = strs.size();
        for(int i = 0;i < m;i++){
            char c = strs[0][i];
            for(int j = 0;j < n;j++){
                if(i == strs[j].size() || strs[0][i] != strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};