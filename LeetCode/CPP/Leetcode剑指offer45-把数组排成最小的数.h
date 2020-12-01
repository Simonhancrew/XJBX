#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//字符串比较的方法，首先比较第一位，然后顺序的比较。如果比较到之后没有的话，字符串长的更大
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vecs;
        for(auto num:nums){
            vecs.push_back(to_string(num));
        }
        //注意不能淡出的按照字符串大小进行排序
        //会出现30+3 3+30这种不符合要求的情况
        //要按相加之后的大小进行排序
        sort(vecs.begin(),vecs.end(),[](const string &lhs,const string &rhs){
            return lhs + rhs < rhs + lhs;
        });
        string ret;
        for(auto vec:vecs){
            ret += vec;
        }
        return ret;
    }
};