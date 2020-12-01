#include <string>
#include <algorithm>
using namespace std;
//不使用额外空间的话

/*
参考151
先翻转前n，再翻转n到结尾
最后整体翻转一次就是结果
*/
class Solution {
    string reverseLeftWords(string &s, int n) {
        //左闭右开
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};