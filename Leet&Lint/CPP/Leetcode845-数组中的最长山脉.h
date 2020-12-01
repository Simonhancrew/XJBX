//什么样的情况下双指针？
//前后双指针，逆序交换或者是数组有序的
//都是前进的双指针，找一个区间
#include <vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0;
        int res = 0;
        int end = A.size();
        if(end < 3){
            return 0;
        }
        //双指针，固定左边的，剩下的数字要大于3
        while(left+2 < end){
            //右边的指针，先找山峰，后找山脚
            int right = left + 1;
            //确定是递增的
            if(A[left] < A[left + 1]){
                //找山峰
                while(A[right] < A[right + 1] && right + 1 < end){
                    ++right;
                }
                //确定不越界，递减
                if(right < end - 1 && A[right] > A[right+1]){
                    //找山脚
                    while(right + 1 < end && A[right] > A[right + 1]){
                        ++right;
                    }
                    //找到山脚，看看能不能更新
                    res = max(res,right - left + 1);
                }else{
                    //例外的情况，比如剩下的数组不组成递减的部分，或者不够了
                    ++right;
                }
            }
            left = right;
        }
        return res;
    }
};