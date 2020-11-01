#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set(wordDict.begin(),wordDict.end());
        backtrack(s,0);
        return res[0];
    }
    void backtrack(const string &s,int index){
        //当前的没有处理过才处理
        if(res.find(index) ==res.end()){
            if(index == s.size()){
                res[index] = {""};
                return;
            }
            res[index] = {};
            for(int i = index + 1;i <= s.size();++i){
                string cur = s.substr(index,i-index);
                if(wordSet.find(cur) != wordSet.end()){
                    //找之后的
                    backtrack(s,i);
                    for(auto succ:res[i]){
                        res[index].push_back(succ.empty() ? cur:cur+" "+succ);
                    }
                }
            }
        }
    }
private:
    //在indx位置能组成的句子组合
    unordered_map<int,vector<string>> res;
    //一个查询字符串是否存在的集合
    unordered_set<string> wordSet;
};