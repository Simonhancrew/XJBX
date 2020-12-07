#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    string shortestPalindrome(string s) {
        //如果他本身就是一个回文串，返回原s
        if(s.empty()||judgePalindrome(s)){
            return s;
        }
        //不是回文串的话
        addString(s);
        return s;
    }
private:
    bool judgePalindrome(const string &s){
        int begin = 0,end = s.size()-1;
        while(begin<end){
            if(s[begin]!=s[end]) return false;
            begin++,end--;
        }
        return true;
    }
    void addString(string &s){
        //manacher找到回文部分，4种情况，
        //回文在开头，reverse复制串尾非回文的部分，加到开头
        //回文在中部或者在尾部，或者完全没有回文的话，reverse复制一整个串，加到开头
    }
};
//用kmp，连接s和s逆，最长公共前后缀就是回文部分，，其余部分逆放前面就可以
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//用kmp，连接s和s逆，最长公共前后缀就是回文部分，，其余部分逆放前面就可以
class Solution2 {
public:
    int compute_next(const string& pattern) {
        vector<int> next(pattern.size() + 1, 0);
        next[0] = -1;
        next[1] = 0;
        //pos遍历next数组，jump是最长前缀的下标后一位
        int pos = 2, jump = 0;
        while (pos < next.size()) {
            if (pattern[pos - 1] == pattern[jump]) {
                next[pos] = jump + 1;
                jump = next[pos];
                ++pos;
            }
            else if (jump == 0) {
                next[pos] = 0;
                pos++;
            }
            else {
                jump = next[jump];
            }
        }
        return next[next.size() - 1];
    }

    string shortestPalindrome(const string& s) {
        if (s == "") {
            return "";
        }
        string reverseTheString (s.size(),' ');
        reverseTheString.reserve(s.size());
        reverse_copy(s.begin(), s.end(), reverseTheString.begin());
        string pattern = s + '#' + reverseTheString;
        int max_len = compute_next(pattern);
        return reverseTheString.substr(0, reverseTheString.size() - max_len) + s;
    }
};