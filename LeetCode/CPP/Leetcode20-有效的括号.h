#pragma once
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                if (ch == ')' && top != '(') return false;
                if (ch == ')' && top == '(') {
                    st.pop();
                    continue;
                }
                if (ch == ']' && top != '[') return false;
                if (ch == ']' && top == '[') {
                    st.pop();
                    continue;
                }

            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};