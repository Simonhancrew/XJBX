#include <string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = handleback(S);
        string t = handleback(T);
        if(s == t){
            return true;
        }
        return false;
    }
private:
    string handleback(string &S){
        string res;
        for(auto s:S){
            if(s != '#'){
                res.push_back(s);
            }else if(s == '#' && res.size()>0){
                res.pop_back();
            }
        }
        return res;
    }
};

//双指针，删除数组中的元素
//从最后开始往前
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};