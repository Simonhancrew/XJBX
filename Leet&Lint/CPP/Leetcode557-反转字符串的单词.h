#include <string>
using namespace std;
class Solution{
    string reverseWords(const string &s) {
        string cur = "";
        int length = s.size();
        int i = 0;
        while(i<length){
            int start = i;
            while(i<length && s[i] != ' '){
                i++;
            }
            for(int p = start;p < i;p++){
                cur.push_back(s[start+i-1-p]);
            }
            while(i<length&&s[i] == ' '){
                i++;
                cur.push_back(' ');
            }
        }
        return cur;
    }
};