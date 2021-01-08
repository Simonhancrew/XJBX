#include <vector>
using namespace std;
//额外利用n的空间
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0){
            return;
        }
        int n = nums.size();
        vector<int> tmp(n,0);
        for(int i = n - 1;i >= 0;--i){
            int shift_index = (i + k) % n;
            tmp[shift_index] = nums[i];
        } 
        nums = tmp;
    } 
};

//考虑原地的转换
//数组前向移动k之后，尾部的k mod n 个元素会移动到数组的头部
//后几个元素向后移动k mod n
class Solution {
public:
    void reverse(vector<int>& nums,int start,int end){
        while(start < end){
            swap(nums[start],nums[end]);
            end--;
            start++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        //考虑k移动的超过数组的长度
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    } 
};