#include <string>

using namespace std;

class Solution {
public:
    const pair<int,string> hh[13] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
    };
    string intToRoman(int num) {
        string ans;
        for(const auto [l,r]:hh){
            while(num >= l){
                num -= l;
                ans += r;
            }
            if(num == 0) break;
        }
        return ans;
    }
};