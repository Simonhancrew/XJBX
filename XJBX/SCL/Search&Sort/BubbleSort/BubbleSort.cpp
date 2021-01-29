#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//排序的问题一定要建立有序区和无序区的概念
//前几个排序的算法不是分治的实现有序区就是遍历的
void bubble_sort(vector<int> &nums){
    int n = nums.size();
    if(n == 0){
        return;
    }
    bool flag = false;
    for(int i = n - 1;i > 0;i--){
        flag = false;
        for(int j = 0;j < i;j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j],nums[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            break;
        }
    }
    return;
}

#define PRINTARRY(NUMS) do{\
    for(auto num:NUMS){\
        cout<<num<<' ';\
    }\
    cout<<endl; \
}while(0)

int main(){
    vector<int> nums = {3,2,1,2,4,56,7,4,2,332};
    bubble_sort(nums);
    PRINTARRY(nums);
    return 0;
}