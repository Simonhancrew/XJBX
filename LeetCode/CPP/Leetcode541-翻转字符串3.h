#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string &s,int k){
        for(int i =0;i<s.size();i+=(2*k)){
            //剩余字符大于k
            if(i+k <= s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                //剩余的小于k，全部翻转
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};
//不使用库函数进行翻转
class Solution2 {
public:
    string reverseStr(string s,int k){
        for(int i =0;i<s.size();i+=(2*k)){
            if(i+k <= s.size()){
                reverse(s,i,i+k-1);
            }else{
                reverse(s,i,s.size()-1);
            }
        }
        return s;
    }
private:
    void reverse(string &s,int start,int end){
        //取到交换的中心界
        int offset = (end - start+1)/2;
        for(int i =start,j = end;i<start + offset;i++,j--){
            swap(s[i],s[j]);
        }
    }
};