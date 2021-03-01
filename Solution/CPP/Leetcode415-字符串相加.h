#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#include <vector>
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        vector<int> a,b;
        for(int i = num1.size() - 1;i >= 0;i--) a.push_back(num1[i] - '0');
        for(int i = num2.size() - 1;i >= 0;i--) b.push_back(num2[i] - '0');

        vector<int> c;
        int t = 0;
        for(int i = 0;i < a.size() || i < b.size();i++){
            if (i < a.size()) t += a[i];
            if (i < b.size()) t += b[i];
            c.push_back(t % 10);
            t /= 10; 
        }
        if(t) c.push_back(1);
        for(int i = c.size() - 1;i >=0 ;--i){
            ans.push_back(c[i] + '0');
        }   
        return ans;
    }
};