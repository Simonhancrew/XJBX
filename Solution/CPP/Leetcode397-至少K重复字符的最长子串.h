#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
//滑动窗口，枚举字符种类的数量
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ret = 0;
        unordered_set<int> st;
        for(auto chr:s){
            st.insert(chr);
        }
        int nums = st.size();
        for(int i = 0; i <= nums;i++){
            int l = 0,r = 0;
            vector<int> cnt(26,0);
            int less = 0;
            int total = 0;
            while(r < n){
                cnt[s[r] - 'a']++;
                if(cnt[s[r] - 'a'] == 1){
                    less++;
                    total++;
                }
                if(cnt[s[r] - 'a'] == k){
                    less--;
                }
                while(total > i){
                    cnt[s[l] - 'a']--;
                    if(cnt[s[l] - 'a'] == k-1){
                        less++;
                    }
                    if(cnt[s[l] - 'a'] == 0){
                        total--;
                        less--;
                    }
                    l++;
                }
                if(less == 0){
                    ret = max(ret,r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }
};


//分治
//小于k的字符在一定拼不成，分割成多个段，每个段看最大是多少
class Solution {
public:
    int dfs(string &s,int l,int r,int k){
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i = l;i <= r;i++){
            cnt[s[i] - 'a']++;
        }
        char split = 0;
        for(int i =0;i < 26;i++){
            if (cnt[i] > 0 && cnt[i] < k){
                split = i + 'a';
                break;
            }
        }
        if(split == 0){
            return r - l + 1;
        }
        int i = l;
        int ret = 0;
        while(i <= r){
            while(i <= r && s[i] == split){
                i++;
            }
            if(i > r){
                break;
            }
            int start = i;
            while(i <= r && s[i] != split){
                i++;
            }
            int len = dfs(s,start,i-1,k);
            ret = max(ret,len);
        }
        return ret;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ret = dfs(s,0,n - 1,k);
        return ret;
    }
};