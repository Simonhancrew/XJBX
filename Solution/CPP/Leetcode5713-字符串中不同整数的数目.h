#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> h;
        for(int i = 0;i < word.size();i++){
            if(!isdigit(word[i])) continue;
            string s;
            int j = i;
            while(j < word.size() && isdigit(word[j])){
                s += word[j++];
            }
            int  k = 0;
            while(k + 1 < s.size() && s[k] == '0') k++;
            h.insert(s.substr(k));
            i = j;
        }
        return h.size();
    }
};