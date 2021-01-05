#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = 0,end = 0;
        int n = s.size();
        vector<vector<int>> res;
        while(end < n){
            if(s[end] == s[start]){
                end++;
            }else{
                int len = end - start;
                if(len >= 3){
                    res.push_back({start,end - 1});
                }
                start = end;
            }
        }
        if(end - start >= 3){
            res.push_back({start,end - 1});
        }
        return res;
    }
};