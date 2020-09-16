#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens){
        stack<int> st;
        for(auto token:tokens){
            if(token == "+"||token == "-" || token == "*" || token == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(token == "+") st.push(num1+num2);
                //pay attention the order
                if(token == "-") st.push(num2-num1);
                if(token == "*") st.push(num1*num2);
                //pay attention the order
                if(token == "/") st.push(num2/num1);
            }
            else{
                int toiToken = stoi(token);
                st.push(toiToken);
            }
        }
        auto res = st.top();
        st.pop();
        return res;
    }
};