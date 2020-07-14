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