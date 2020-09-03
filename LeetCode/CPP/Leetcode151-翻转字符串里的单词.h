#include <string>
#include <algorithm>
using namespace std;
/*
去除空格 -> 双指针
翻转整个字符串 -> swap头尾
单词翻转 -> 进入单词区域，反转，结束。->最后一个单词末尾没有空格，特殊判断
*/
class Solution {
public:
    string reverseWords(string &s){
        removeSpace(s); // 去掉冗余空格
        reverse(s, 0, s.size() - 1); // 将字符串全部反转
        int start = 0; // 反转的单词在字符串里起始位置
        int end = 0; // 反转的单词在字符串里终止位置
        bool entry = false; // 标记枚举字符串的过程中是否已经进入了单词区间
        for (int i = 0; i < s.size(); i++) { // 开始反转单词
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i; // 确定单词起始位置
                entry = true; // 进入单词区间
            }
            // 单词后面有空格的情况，空格就是分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1; // 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
            // 最后一个结尾单词之后没有空格的情况
            if (entry && (i == (s.size() - 1)) && s[i] != ' ' ) {
                end = i;// 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
        }
        return s;
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
        for(;fastIndex<s.size();fastIndex++){
            //去掉中间字符串的冗余
            if(fastIndex - 1 > 0 
                && s[fastIndex-1] == s[fastIndex] 
                && s[fastIndex] == ' '){
                    continue;
                }else{
                    s[slowIndex++] = s[fastIndex];
                }
        }
        //去掉尾部的空格 ->   a space space slowindex>=2   
        if(slowIndex - 1 >0 && s[slowIndex -1] == ' '){
            s.resize(slowIndex - 1);
        }else{
            s.resize(slowIndex);
        }
        
    }  
};