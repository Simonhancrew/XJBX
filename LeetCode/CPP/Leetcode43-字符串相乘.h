#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            //for loop 是为了补0，进位之后的乘法后面会补上相应的0
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }
private:
    string addStrings(string &num1,string &num2){
        int n = num1.size()-1,m = num2.size()-1;
        int add = 0;
        string ans = "";
        while(n >= 0 ||m >= 0 ||add!=0){
            int x = n>=0?num1[n] - '0':0;
            int y = m>=0?num2[m] - '0':0;
            int res = x+y+add;
            add = res / 10;
            res = res % 10;
            ans.push_back('0'+res);
            m--,n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }   
};