#include <string>
#include <stack>
using namespace std;
//利用栈去保存他的边界
//最开始的时候栈底会有他的右边界，就是最后一个没匹配的右括号下标
//然后遇到'('的时候push入，遇到')'的时候pop
//如果某次pop的时候栈为空了，说明这个右括号没有匹配的，更新边界，push入
//最开始需要push（-1），最开始没有未匹配的')',设为dummy
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxL = 0;
        int n = s.size();
        stk.push(-1);
        for(int i = 0;i < n;++i){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    maxL = max(maxL,i - stk.top());
                }
            }
        }
        return maxL;
    }
};

//动态规划，找到对应的左括号