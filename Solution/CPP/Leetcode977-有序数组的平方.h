#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res;
        for(int i = 0;i<n;i++){
            res.push_back(A[i]*A[i]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//利用数组有序的先验条件
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A){
        int n = A.size();
        int negative = -1;
        //找到分割点
        for (int i = 0; i < n; ++i) {
            if (A[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }
        vector<int> ans;
        int i = negative, j = negative + 1;
        //一个merge的操作
        while (i >= 0 || j < n) {
            if (i < 0) {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
            else if (j == n) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else if (A[i] * A[i] < A[j] * A[j]) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        vector<int> ans(nums.size());
        int k = ans.size() - 1;
        while(i <= j){
            int lm = nums[i] * nums[i];
            int rm = nums[j] * nums[j];
            if(lm > rm) ans[k--] = lm,i++;
            else ans[k--] = rm,j--;
        }
        return ans;
    }
};