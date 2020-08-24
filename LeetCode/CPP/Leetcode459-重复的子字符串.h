#include<string>
using namespace std;
//字符串是否重复
class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        //两个s串联，去掉首尾，必定能找到s，
        //coding的时候从1开始，只要这个新s不在s.size()的位置开始就可以认为该串ok
        return (s + s).find(s, 1) != s.size();
    }
};
//暴力匹配
class Solution2 {
public:
    bool repeatedSubstringPattern(const string &s) {
        int n = s.size();
        //找到最大的长度i,这个长度为了能够整除n，最大也不会超过n/2，因为整数乘法比除法快30个时钟周期，所以选择2*i
        for(int i = 1;i*2 <= n;i++){
            if(n%i == 0){
                bool match = true;
                //从i-1之后第一个char开始
                for(int j = i; j < n;j++){
                    //如果s确实有i个s'组成，则s[j-i] ==s[j],j>=i,相当于把j后移了还是该char
                    if(s[j]!=s[j-i]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    return true;
                }
            }
        }
        return false;        
    }
};
//KMP，solution1的查找函数可以自己实现
class Solution3{
    bool kmpFind(const string &text,const string &pattern){

    }
    bool repeatedSubstringPattern(const string &s){
        return kmpFind(s+s,s);
    }
};