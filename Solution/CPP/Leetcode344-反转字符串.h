#include<vector>
using namespace std;
//字符串的反转，删除都可以使用双指针去做
class Solution {
public:
    void reverseString(vector<char> &s){
        for(int i =0,j = s.size()-1;i<s.size()/2;i++,j--){
            swap(s[i],s[j]);
        }
    }
};