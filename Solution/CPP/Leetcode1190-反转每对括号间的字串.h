#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string cur;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                stk.push(cur);
                cur = "";
            }else if (s[i] == ')'){ 
                reverse(cur.begin(),cur.end());
                cur = stk.top() + cur;
                stk.pop();
            }else{
                cur.push_back(s[i]);
            }
        }
        return cur;
    }
};