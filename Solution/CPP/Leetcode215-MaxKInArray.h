class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> Q;
        for (auto i=0;i<nums.size();i++){
            if(Q.size()<k){
                Q.push(nums[i]);
            }
            else if(Q.top()<nums[i]){// pay attention chain judge
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};