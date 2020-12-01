// 滑动窗口
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int sum = 0;
        vector<int> sumArr;
        sumArr.push_back(sum);
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            sumArr.push_back(sum);
        }
        for(auto i =k;i<sumArr.size();i++){
            if(sumArr[i]-sumArr[i-k]>=k*threshold) count++;
        }
        return count;
    }
};