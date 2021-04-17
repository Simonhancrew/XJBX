#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            auto lb = st.lower_bound((long)nums[i] - t);
            if(lb != st.end() && *lb <= (long)nums[i] + t) return true;
            st.insert(nums[i]);
            if(i >= k) st.erase(nums[i - k]);
        }
        return false;
    }
};