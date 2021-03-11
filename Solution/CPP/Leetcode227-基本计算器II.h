#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        char presign = '+';
        vector<int> st;
        int n = s.size();
        int num = 0;
        for(int i = 0;i < n;i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1){
                switch(presign){
                    case '+':
                        st.push_back(num);
                        break;
                    case '-':
                        st.push_back(-num);
                        break;
                    case '*':
                        st.back() *= num;
                        break;
                    default:
                        st.back() /= num;
                }
                presign = s[i];
                num = 0;
            }
        }
        return accumulate(st.begin(),st.end(),0);
    }
};