#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
//需要重新写一遍
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int size=A.size();
        int sum=accumulate(A.begin(),A.end(),0);
        //排序的目的是为了在后续的深搜中递归树的同一层中去重
        sort(A.begin(),A.end());
        //以数组的长度作为依据递增，划分数组要么对半，要么一个多一个少
        for(int i=1;i<=size/2;i++){
            //要满足子数组平均数等于整个数组平均数，则有sum*i==size*subSum,i为子数组长度，
            //subNum为子数组和，显然subNum是整数
            if(sum*i%size==0&&dfs(0,size,i,sum*i/size,A)==true){
                return true;
            }
        }
        return false;
    }

    bool dfs(int start,int size,int cnt,int target,vector<int>&A){
        if(cnt==0){
            return target==0;
        }
        for(int i=start;i<size-cnt+1;i++){
            //如果出现了重复的值，之前就已经考虑这种情况了，剪枝
            if(i!=start&&A[i]==A[i-1]){
                continue;
            }
            //递归求解
            if(dfs(i+1,size,cnt-1,target-A[i],A)==true){
                return true;
            }
        }
        return false;
    }
};