#include <vector>
using namespace std;
class Solution {
public:
    int co(int i,int a){ 
        if(i==0) return a;
        return  a*co(i-1,a-1);
    }
    int countNumbersWithUniqueDigits(int n) {       
        if(n==0) return 1;
        vector<int> dp(n+2);
        dp[0]=0,dp[1]=10,dp[2]=91;
        for(int i=3;i<=n;i++)
        dp[i]=co(i-1,10)+dp[i-1]-co(i-2,9); 
        return dp[n];
    }
};

//回溯，空间差不多，但是时间复杂度高
class Solution2 {
public:
    int countNumbersWithUniqueDigits(int n){
        if(n == 0) return 1;
        vector<int> num(10,0);
        DFS(n,1,num);
        //剪枝决定了n>2时不能以0开始，少算了0的情况
        if(n>1){
            count++;
        }
        return count;
    }
private:
    int count = 0;
    void DFS(int n,int index,vector<int>& number){
        if(index>n){
            return;
        }
        for(int i = 0;i<=9;i++){
            //在1位置，n的位数大于1，不能为0
            if(index == 1 && i == 0 && number[i] == 0 && n>1){
                continue;
            }
            if(number[i] == 1){
                continue;
            }
            number[i] = 1;
            ++count;
            DFS(n,index+1,number);
            number[i] = 0;
        }
    }
};