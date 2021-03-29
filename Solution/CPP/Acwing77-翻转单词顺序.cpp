#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        for(int i = 0;i < s.size();i++){
            int j = i + 1;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i,s.begin() + j);
            i = j;
        }        
        return s;
    }
};