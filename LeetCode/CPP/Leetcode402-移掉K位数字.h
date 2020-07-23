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