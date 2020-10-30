#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//更优化空间可以自己压栈
/* 一个回溯的模板
backtracking() {
    if (终止条件) {
        存放结果;
    }

    for (枚举同一个位置的所有可能性，可以想成节点孩子的数量) {
        递归，处理节点;
        backtracking();
        回溯，撤销处理结果
    }
}
*/
//首先一个字母和数字的映射，找到回溯的宽度
//然后回溯的深度就是数字的个数
//其实还应该考虑错误的数字，比如按1和* #，但测试数据没有这种
class Solution{
public: 
    vector<string> letterCombinations(const string &digits){
        cur.clear();
        result.clear();
        if(digits.empty()){
            return result;
        }
        BackTrait(digits,0);
        return result;
    }
private:
    //当前的可行字符
    string cur = "";
    //储存最后的结果
    vector<string> result;
    //数字字母映射
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
    //回溯
    void BackTrait(const string &digits,int index){
        //终止条件
        if(index == digits.size()){
            result.push_back(cur);
            return;
        }else{
            //当前的数字
            char digit = digits[index];
            //映射的可能字母
            const string &letters = Digit2Alpha.at(digit);
            //宽度回溯
            for(const char& letter:letters){
                cur.push_back(letter);
                //深度回溯
                BackTrait(digits,index+1);
                cur.pop_back();
            }
        }
    }
};
