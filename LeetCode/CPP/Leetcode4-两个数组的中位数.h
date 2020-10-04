#include <vector>
#include <queue>
using namespace std;
//优先队列
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int,vector<int>,greater<int>> que;
        int size = (nums1.size()+nums2.size())/2+1;
        for(int i =nums1.size()-1;i>=0;--i){
            if(que.size()<size||que.top()<nums1[i]){
                if(que.size()<size){
                    que.push(nums1[i]);
                }
                else{
                    que.pop();
                    que.push(nums1[i]);
                }
            }
        }
        for(int i = nums2.size()-1;i>=0;--i){
            if(que.size()<size||que.top()<nums2[i]){
                if(que.size()<size){
                    que.push(nums2[i]);
                }
                else{
                    que.pop();
                    que.push(nums2[i]);
                }
            }
        }
        if((nums1.size()+nums2.size())%2==0){
            double res = 0;
            res+=que.top();
            que.pop();
            res+=que.top();
            res=res/2;
            return res;
        }
        else{
            double res = 0;
            res += que.top();
            return res;
        }
    }
};
//还可以merge两个数组。还有双指针，较小的往前跳，有一个到了末尾，另一个只需要往前走
//二分查找
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
private:
    //利用二分查找，找到两个有序数组中的第k个数字。
    int getKthElement(const vector<int> &nums1,const vector<int> &nums2,int k){
        //在整个过程中不断的排除，所以要记录上一次排除的位置
        int index1 = 0;
        int index2 = 0;
        int m =nums1.size(),n = nums2.size();
        while(true){
            //结束+特殊情况的排除
            //1.整个数组全部被排除
            //2.k缩减到1
            if(index1 == m){
                //完全排除了s1，这个时候我们拿到s2的绝对下标位置，然后找到这个时候s2的第k位数
                //就是总体的第k位数
                return nums2[index2+k-1];
            }
            if(index2 == n){
                return nums1[index1+k-1];
            }
            if(k == 1){
                //不断排除的过程就是不断缩小k的过程
                return min(nums1[index1],nums2[index2]);
            }
            //边界处理
            int newindex1 = min(index1+k/2-1,m-1);
            int newindex2 = min(index2+k/2-1,n-1);
            //更新排除掉了的数组的绝对位置
            int pivot1 = nums1[newindex1],pivot2 = nums2[newindex2];
            if(pivot1 <= pivot2){
                k-= newindex1-index1+1;
                index1 = newindex1+1;
            }else{
                k-=newindex2-index2+1;
                index2 = newindex2+1;
            }
        }
    }
};