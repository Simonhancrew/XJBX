#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    string multiply(string &num1, string &num2) {
        
    }
private:
    string add(string &num1,string &nums2){
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