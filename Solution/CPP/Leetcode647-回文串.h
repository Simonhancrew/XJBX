#include<string>
#include<vector>
#include<algorithm>
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
//第二种方法可以使用manacher,blog上有解析，但是写的不到位，2020/08/20我回重新写详细。
//虽然manacher最后得到的是最大回文的长度，但是在扩充的每一步i下他都得到了能扩的最大的回文半径，并将他储存在数组中
//实质上就是一个动态规划
class Solution2{
public:
    int countSubstrings(const string &s){
        //首先扩充字符串，让奇数偶数都可以处理，在字符串前后加入特殊不相等的字符，这就能保证之后的循环在到达此处时一定结束
        string help = "^#";
        for(auto word:s){
            help += word;
            help += '#';
        }
        help += '$';
        int n = help.size();
        auto f = vector<int> (n);//其实说到底manacher也是一种动态规划
        int iMax = 0,rMax = 0,result = 0;
        for(int i =1;i<n-1;i++){//最初和最后的没必要进入循环，省点时间
            //开始扩展每个字符的回文半径,三种情况，但只要i在回文界内，最少都是min(f[2*iMax-i],rMax-i+1)
            f[i] = (i<rMax)?min(f[2*iMax-i],rMax-i+1):1;
            //中心扩展，在回文界内需要判断回文界是否可以更新。不在回文界就判断新的回文半径和回文中心
            //之前的help前后加^和$就是为了在判断中不让下标越界，不然还要判断越界的问题
            while(help[i+f[i]] == help[i-f[i]]) ++f[i];
            if(i+f[i]-1>rMax){
                iMax = i;//需要更新以下回文半径和新的和新的回文中心
                rMax = i+f[i]+1;
            }
            //结果就是每一个(f[i]-1)/2的累加，向上取整->是s中的字符代表奇数中心，#代表偶数中心
            result += (f[i]/2 );
        }
        return result;
    }
};