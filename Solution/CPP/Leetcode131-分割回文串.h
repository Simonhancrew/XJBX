#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
private:
    //回文的判断，双指针
    bool isPalindrome(const string &s,int start,int end){
        while(start < end){
            if(s[start] == s[end]){
                ++start,--end;
            }else{
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> res;
    vector<string> path;
    void backtrack(const string &s,int startIndex){
        //最后分割的位置达到了结尾之后
        if(startIndex >= s.size()){
            res.push_back(path);
            return;
        }
        //需要startIndex是为了去除重复
        for(int i = startIndex;i < s.size();++i){
            if(isPalindrome(s,startIndex,i)){
                string str = s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
            }else{
                continue;
            }
            //寻找i+1位置开始的子串
            backtrack(s,i+1);
            //回溯，比如最开始截取了单个字符，pop掉，去找更长的回文
            path.pop_back();
        }
    }
};