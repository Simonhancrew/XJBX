#include <string>
#include <algorithm>
using namespace std;
/*
去除空格
翻转整个字符串
单词翻转
*/
class Solution {
public:
    string reverseWords(string &s){

    }
private:
    //反字符串
    void reverse(string& s,int start,int end){
        for(int i = start,j = end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    void removeSpace(string &s){
        int slowIndex = 0,fastIndex = 0;
        //去掉头空格
        while(s.size() > 0 && fastIndex <s.size()&&s[fastIndex] == ' '){
            fastIndex++;
        }
        //去掉中间空格
        
    }  
};