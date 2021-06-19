#include <vector>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int st[26];
        bool flag = true;
        int ans = 0;
        for(int i = 0;i < (1 << n);i++){
            memset(st,0,sizeof st);
            flag = true;
            for(int j = 0;j < n;j++){
                if((i >> j) & 1){
                    for(auto ch:arr[j]){
                        st[ch -'a']++;
                        if(st[ch - 'a'] > 1){
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) break;
            }
            if(flag) ans = max(ans,accumulate(st,st + 26,0));
        }
        return ans;
    }
};