#include <string>
#include <unordered_map>
using namespace std;
//哈希
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> match;
        for(auto chr:s){
            match[chr]++;
        }
        for(auto chr:t){
            if(match[chr] <= 0){
                return chr;
            }else{
                match[chr]--;
            }
        }
        return ' ';
    }
};
//为什么不计数呢？
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> table(26,0);
        for(auto chr:s){
            table[chr - 'a']++;
        }
        for(auto chr:t){
            table[chr - 'a']--;
            if(table[chr - 'a'] < 0){
                return chr;
            }
        }
        return ' ';
    }
};

//为什么不求和呢？
class Solution {
public:
    char findTheDifference(string s, string t){
        int ss = 0,st = 0;
        for(auto chr:s){
            ss += chr;
        }
        for(auto chr:t){
            st += chr;
        }
        return st -ss;
    }
};

//拼接字符串之后位运算
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch: s) {
            ret ^= ch;
        }
        for (char ch: t) {
            ret ^= ch;
        }
        return ret;
    }
};