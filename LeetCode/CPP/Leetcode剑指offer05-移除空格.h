#include <string>
using namespace std;
//双指针处理字符串
//string类结尾‘\0’
//统计空格数，扩充数组，从后向前移除空格，这样就不用将空格后的所有
//元素每次后移
class Solution {
public:
    string replaceSpace(string s) {
        int oldsize = s.size();
        int count = 0;//统计空格
        for(auto chr:s){
            if(chr == ' '){
                ++count; 
            }
        }
        s.resize(s.size()+2*count);
        //双指针，从后往前,i在扩充后的尾部，j在原字符串的尾部
        int newSize = s.size();
        for(int i = newSize-1,j = oldsize-1;j<i;j--,i--){
            if(s[j] != ' '){
                s[i] = s[j];
            }else{
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};