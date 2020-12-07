#include <vector>
using namespace std;
//从nums1取x，从nums2取y。遍历所有可能的xy。并拼接他们，其中 0=<x<nums1.size,
//0<=y <=nums2.size，x+y = k
//然后从中选择最大的返回
//其中x，y各是他们的最大序列，需要merge他们
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(),n = nums2.size();
        vector<int> ret(k,0);
        //从s1中最少和最多取多少个数
        //对于nums1子序列可能的长度取值
        int start = max(k - n,0),end = min(k,m);
        //遍历所有可能的长度
        for(int i = start;i <= end;++i){
            vector<int> sub1(Maxseq(nums1,i));
            vector<int> sub2(Maxseq(nums2,k-i));
            vector<int> curmaxseq(merge(sub1,sub2));
            if(compare(ret,0,curmaxseq,0) < 0){
                ret = curmaxseq;
            }
        }
        return ret;
    }
private:
    //数组构成的单调栈，找到最大子序列
    vector<int> Maxseq(vector<int> &nums,int k){
        int n = nums.size();
        vector<int> seq(k,-1);
        //因为必须填满seq数组，所以需要知道原数组富裕的值
        //有多少可以浪费掉的
        //remain是0时，全部push入，不管单调栈的性质
        int remain = n - k;
        int top = -1;//top开始于dummy位，比index永远少
        for(int i = 0;i < n;++i){
            int num = nums[i];
            while(top >= 0 && seq[top] < num && remain > 0){
                top--;
                remain--;
            }
            if(top < k -1){
                seq[++top] = num;
            }else{
                remain--;
            }
        }
        return seq;
    }
    //merge两个最大子序列，遵从compare的方式
    vector<int> merge(vector<int> &nums1,vector<int> &nums2){
        int x = nums1.size(),y = nums2.size();
        if(x == 0){
            return nums2;
        }
        if(y == 0){
            return nums1;
        }
        int total = x + y;
        vector<int> ret(total,0);
        int index1 = 0,index2 = 0;
        for(int i = 0;i < total;++i){
            if(compare(nums1,index1,nums2,index2) > 0){
                ret[i] = nums1[index1++];
            }else{
                ret[i] = nums2[index2++];
            }
        }
        return ret;
    }
    //不相等传最大，相等继续往后比，如果有一个用尽了，返回没用尽的
    int compare(vector<int> &nums1,int index1,vector<int> &nums2,int index2){
        int x = nums1.size(),y = nums2.size();
        while(index1 < x && index2 < y){
            int diff = nums1[index1] - nums2[index2];
            if(diff != 0){
                return diff;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};