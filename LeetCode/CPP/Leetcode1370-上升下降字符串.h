#include <string>
#include <algorithm>
#include <vector>
//桶排序的思想
using namespace std;
class Solution {
public:
    string sortString(string s) {
        vector<int> word(26);
        for(auto &ch:s){
            word[ch - 'a']++;
        }
        string ret = "";
        while(ret.size() < s.size()){
            for(int i = 0;i < 26;++i){
                if(word[i]){
                    ret.push_back(i + 'a');
                    --word[i];
                }
            }
            for(int i = 25;i >= 0;--i){
                if(word[i]){
                    ret.push_back(i + 'a');
                    --word[i];
                }
            }
        }
        return ret;
    }
};