#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;
        char used[128] = { 0 };
        string word;
        int pos=0;
        str.push_back(' ');
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                if (pos == pattern.length()) {
                    return false;
                }
                if (word_map.find(word) == word_map.end()) {
                    if (used[pattern[pos]] != 0) {
                        return false;
                    }
                    used[pattern[pos]] = 1;
                    word_map[word] = pattern[pos];
                }
                else {
                    if (word_map[word] != pattern[pos]) {
                        return false;
                    }
                }
                word = "";
                pos++;
            }
            else {
                word += str[i];
            }
        }
        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};

//两个哈希表，一个双映射
//需要考虑string边界的问题
#include <unordered_map>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> str2chr;
        unordered_map<char,string> chr2str;
        string cur = "";
        int index = 0;
        int m = s.size();
        for(auto ch:pattern){
            if(index >= m){
                return false;
            }
            int j = index;
            while(j < m && s[j] != ' ') j++;
            auto tmp = s.substr(index,j - index);
            if(str2chr.count(tmp) && str2chr[tmp] != ch){
                return false;
            }
            if(chr2str.count(ch) && chr2str[ch] != tmp){
                return false;
            }
            str2chr[tmp] = ch;
            chr2str[ch] = tmp;
            index = j + 1;
        }
        //patter结束，但是string过长
        return index >= m;
    }
};