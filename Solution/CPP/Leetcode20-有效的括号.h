#pragma once
#include<stack>
#include<string>
using namespace std;
//没必要每个括号都入栈，直接入栈应匹配的，到相应位置时将此处括号和栈顶对比
//空间复杂度会降低
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if(ch == '(') st.push(')');
            else if(ch == '{') st.push('}');
            else if(ch == '[') st.push(']');
            //不匹配或者栈提前变空了
            else if(st.empty()||st.top() != ch) return false;
            //匹配成功，弹出
            else st.pop();
        }
        //结束的时候如果栈不空的话就没有匹配成功
        return st.empty();
    }
};