#include <string>
#include <vector>
using namespace std;
//典型的分治思想
//加括号的思想其实就是划分
//那我们遇到符号久划分成两个式子，将问题变小
//分：将式子划分小->遇到运算符，将式子分两部分
//治：在分的步骤中提前记录运算符->分的每一部分的结果是多少，这个数组里可能存多个值->按照记录的运算符将结果处理
//分到最后其实就是单个的数字，递归结束的终止就是把这个数字转成int，然后push入数组中
class Solution {
public:
    //相信函数签名
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0;i < input.size();++i){
            //记录这个char
            char c = input[i];
            //char是运算符
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                //左边处理的结果
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                //右边处理的结果
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                //对两边 结果的综合
                for(auto &lhs:left){
                    for(auto &rhs:right){
                        if(c == '+'){
                            res.push_back(lhs + rhs);
                        }else if(c == '-'){
                            res.push_back(lhs - rhs);
                        }else if(c == '*'){
                            res.push_back(lhs * rhs);
                        }
                    }
                }
            } 
        }
        //递归的结束条件,这部分里面完全没有包含运算符
        //那就只有一个数字,将这个字符串转为整数
        if(res.empty()){
            res.push_back(stoi(input));
        }
        return res;
    }
};