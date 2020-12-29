#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> row(min(numRows,int(s.size())));
        int currow = 0;
        bool goDown = false;
        for(auto ch:s){
            row[currow] += ch;
            //只有在开头和结尾才转向
            if(currow == 0||currow == numRows - 1) goDown = !goDown;
            currow += goDown==false?-1:1;
        }
        string res = "";
        for(auto str:row){
            res += str;
        }
        return res;
    }
};