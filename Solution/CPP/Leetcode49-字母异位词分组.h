#pragma once
#include <iostream>
#include <vector>
#include<string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ange;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (ange.find(str) == ange.end()) {
                vector<string> item;
                ange[str] = item;
            }
            ange[str].push_back(strs[i]);
        }
        for (auto it = ange.begin(); it != ange.end(); it++) {
            result.push_back((*it).second);
        }
        return result;
    }
};