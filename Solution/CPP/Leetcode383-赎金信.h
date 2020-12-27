#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()){
            return false;
        }
        vector<int> words(26,0);
        for(auto s:magazine){
            words[s - 'a']++;
        }
        for(auto ch:ransomNote){
            words[ch - 'a']--;
            if(words[ch - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};