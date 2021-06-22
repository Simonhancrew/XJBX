#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> st;
    vector<string> ans;
    string cur;
    vector<string> permutation(string& s) {
        sort(s.begin(),s.end());
        st.resize(s.size(),false);
        dfs(s,0);
        return ans;
    }
    void dfs(string &s,int idx){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0;i < s.size();i++){
            if(i > 0 && st[i - 1] == false && s[i] == s[i - 1]) continue;
            if(!st[i]){
                st[i] = true;
                cur.push_back(s[i]);
                dfs(s,idx + 1);
                st[i] = false;
                cur.pop_back();
            }
        }
    }
};