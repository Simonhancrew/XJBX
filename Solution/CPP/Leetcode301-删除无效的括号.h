#include <unordered_set>
#include <vector>
using namespace std;
//1 合法情况下，左右括号数相等
//2 任意一个前缀，左括号都是应该大于右括号的
//所以可以处理出来所有需要删除的左右括号的数量之后去做dfs
class Solution {
public:
    unordered_set<string> hash;//去重
    vector<string> removeInvalidParentheses(string s) {
        int l = 0,r = 0;//需要删除的左右括号的数量
        for(auto ch:s){
            if(ch == '('){
                l++;
            }else if(ch == ')'){
                if(l > 0){
                    l--;
                }else{
                    r++;
                }
            }
        }
        dfs(s,0,"",0,l,r);
        vector<string> ans;
        for(auto s:hash) ans.push_back(s);
        return ans;
    }
    void dfs(string &s,int idx,string res,int cnt,int l,int r){//cnt是当前左括号减去右括号的数目，保证前缀有效
        if(idx == s.size()){
            if(cnt == 0) hash.insert(res);
            return;
        }
        if(s[idx] == '('){//删除要考虑还能不能删
            dfs(s,idx + 1,res + '(',cnt + 1,l,r);
            if(l > 0) dfs(s,idx + 1,res,cnt,l - 1,r);
        }else if(s[idx] == ')'){//同理，保留和删除都要考虑合法性
            if(cnt > 0) dfs(s,idx + 1,res + ')',cnt -  1,l,r);
            if(r > 0) dfs(s,idx + 1,res,cnt,l,r-1);
        }else{//题目中还有合法的字符
            dfs(s,idx + 1,res + s[idx],cnt,l,r);
        }
    }
};