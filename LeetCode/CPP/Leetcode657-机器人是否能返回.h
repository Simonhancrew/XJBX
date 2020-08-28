#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool judgeCircle(const string &moves) {
        unordered_map<char,pair<int,int>> direction = {
            {'R',{1,0}},
            {'L',{-1,0}},
            {'U',{0,1}},
            {'D',{0,-1}}
        };
        pair<int,int> res = {0,0};
        for(const char &move:moves){
            pair<int,int> cur = direction[move];
            res.first+=cur.first;
            res.second+=cur.second;
        }
        return res.first == 0 && res.second == 0;
    }
};