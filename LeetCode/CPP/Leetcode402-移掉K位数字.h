#pragma once
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        vector<int> s;
        for (auto i = 0; i < num.size(); i++) {
            int number = num[i] - '0';
            while (s.size() != 0 && s.back() > number && k > 0) {
                s.pop_back();
                k--;
            }
            if (number != 0 || s.size() != 0) {
                s.push_back(number);
            }
        }
        while (s.size() > 0 && k > 0) {
            s.pop_back();
            k--;
        }
        for (auto i = 0; i < s.size(); i++) {
            result.append(1, s[i] + '0');
        }
        if (result == "") {
            return "0";
        }
        return result;
    }
};

//单调栈+贪心的策略
//删除数字的逻辑，在递增的数列中找到第一个减序之后pop到不减
//找不到就从尾部pop
class Solution {
public:
    string removeKdigits(string num,int k) {
        vector<char> s;
        for(const auto &digit:num){
            //形成一个单调栈
            while(s.size() > 0 && s.back() > digit && k > 0){
                s.pop_back();
                --k;
            }
            s.push_back(digit);
        }
        //还有k的话就直接pop尾部
        for(;k>0;--k){
            s.pop_back();
        }
        string res = "";
        //如果有先导的0
        bool leadingZero = true;
        for(auto &digit:s){
            if(leadingZero && digit == '0'){
                continue;
            }
            //先导0结束了，标记
            leadingZero = false;
            res += digit;
        }
        //可能存在空的例子
        return res == ""?"0":res;
    }
};