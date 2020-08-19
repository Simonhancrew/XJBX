#include<string>
using namespace std;
//最简单的方法，直接暴露扩，找到所有可能的回文中心，然后往两边扩大
//扩的时候有偶数和奇数的情况，可以写两个for loop，但是也可以一个循环搞定。
/*
1.所有的单中心点扩->n
2.所有的双中心点扩->n-1
一共2n-1
left和right就可以选择为i/2和i/2+(i%2)
*/
class Solution{
public:
    int countSubstrings(const string &s){
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int result = 0;
        for(int i = 0;i< 2*n-1;i++){
            int l = i / 2, r = i / 2 + i % 2;
            while(l >= 0&& r<=n && s[l] == s[r]){
                l--,r++;
                result++;
            }
        }
        return result;
    }
};
//第二种方法时选择manacher,blog上有解析，但是写的不到位，2020/08/20我回重新写详细。
class Solution2{
public:
    int countSubstrings(const string &s){
        
    }
};