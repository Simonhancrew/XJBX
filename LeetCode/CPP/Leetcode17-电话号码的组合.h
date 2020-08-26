#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//最好到临界区加回溯，然后找准进入result的条件
//更优化空间可以自己压栈
//循环可以加到递归函数里，没必要放外面
class Solution{
public:
    vector<string> letterCombinations(const string &digits){
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        string cur = "";
        unordered_map<char,string> Digit2Alpha{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        BackTrait(digits,cur,Digit2Alpha,result,0);
        return result;
    }
private:
    void BackTrait(const string &digits,string &cur,const unordered_map<char,string> &Digit2Alpha,vector<string> &result,int index){
        if(index == digits.size()){
            result.push_back(cur);
        }else{
            char digit = digits[index];
            const string &letters = Digit2Alpha.at(digit);
            for(const char& letter:letters){
                cur.push_back(letter);
                BackTrait(digits,cur,Digit2Alpha,result,index+1);
                cur.pop_back();
            }
        }
    }
};
