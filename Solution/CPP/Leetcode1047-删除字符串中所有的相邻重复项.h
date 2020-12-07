#include <string>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for(auto s:S){
            if(st.empty()||s!= st.top()){
                st.push(s);
            }else{
                st.pop();
            }
        }
        string result = "";
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};