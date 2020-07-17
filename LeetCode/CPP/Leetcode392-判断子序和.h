#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int place = -1;
        for(auto i = 0;i<s.size();i++){
            place =firstplace(s[i],t,place+1);
            if (place ==-1) return false;

        }
        return true;
    }
private:
    int firstplace(char c,string &t,int place){
        for(auto i = place;i<t.size();i++){
            if( c == t[i]){
                return i;
            }
        }
        return -1;
    }
};