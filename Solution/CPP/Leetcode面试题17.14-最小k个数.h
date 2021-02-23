#include <vector>
using namespace std;
//还可以用快速选择算法
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        quickSort(arr,0,n-1);
        vector<int> ans;
        for(int i = 0;i < k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
private:
    void quickSort(vector<int> &arr,int l,int r){
        if(l >= r){
            return;
        }
        int x = arr[l + r >> 1],i = l - 1,j = r + 1;
        while(i < j){
            do i++;while(arr[i] < x);
            do j--;while(arr[j] > x);
            if(i < j) swap(arr[i],arr[j]);
        } 
        quickSort(arr,l,j);
        quickSort(arr,j + 1,r);
    }
};