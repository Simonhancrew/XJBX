#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> h;
        for(auto &e:knowledge) h[e[0]] = e[1];
        string res = "";
        for(int i = 0;i < s.size();i++){
            if(s[i] != '(') res += s[i];
            else{
                string key;
                int j = i + 1;
                while(s[j] != ')') key += s[j++];
                i = j;
                if(h.count(key)) res += h[key];
                else res += '?';
            }
        }
        return res;
    }
};