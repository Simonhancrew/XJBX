#include <vector>
#include <unordered_map>
using namespace std;
//类似于这种可以考虑状态机，做一个装填转移
//1 列一个表，纵轴初始状态，横轴符号，每一栏是转换符号
//2 用一个map映射状态的变化
//3 连续getchar，拿到最后的转换值
#include <ctype.h>
class Autochange{
public:
    int sign = 1;
    long long ans = 0;
    void get(char c){
        state = table[state][getState(c)];
        if(state == "in_number"){
            ans = ans * 10 + c - '0';
            //题意要求的范围
            ans = sign == 1?min(ans,(long long)INT_MAX):min(ans, -(long long)INT_MIN);
        }else if(state == "signed"){
            sign = c == '+'?1:-1;
        }
    }
private:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int getState(char c){
        if(isspace(c)) return 0;
        if(c == '+' || c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }   
};
class Solution {
public:
    int myAtoi(string s) {
        Autochange automachine;
        for(auto c : s){
            automachine.get(c);
        }
        return automachine.ans*automachine.sign;
    }
};