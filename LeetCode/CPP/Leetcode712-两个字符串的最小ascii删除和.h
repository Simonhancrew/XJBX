#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> memo;
    int minimumDeleteSum(string &s1, string &s2) {
        int t1 = s1.size(),t2 = s2.size();
        //二维数组的resize
        vector<int> temp(t2,-1);
        memo.resize(t1,temp);
        return dp(s1,0,s2,0);
    }
private: 
    int dp(string &text1,int i, string &text2, int j){
        int res = 0;
        //1 达到终点，后面的全删
        if(i == text1.size()){
            for(;j<text2.size();++j){
                res += (int)text2[j];
            }
            return res;
        }
        if(j == text2.size()){
            for(;i<text1.size();++i){
                res += (int)text1[i];
            }
            return res;
        }
        //如果之前出现在记忆数组中过
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        //如果当前二者相等，这个值是不用删除的
        if(text1[i] == text2[j]){
            memo[i][j] = dp(text1,i+1,text2,j+1);
        }else{
            //当前不等，两者之一前进一个，删除其一，选择小的值
            memo[i][j] = min(text1[i]+dp(text1, i + 1, text2, j), text2[j] +dp(text1, i, text2, j + 1));
        }
        return memo[i][j];
    }   
};