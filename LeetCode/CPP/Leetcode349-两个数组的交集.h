#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> ls;
        for(auto num1:nums1){
            ls.insert(num1);
        }
        sort(nums2.begin(),nums2.end());
        for(int i =0;i<nums2.size();i++){
            if(i>0 && nums2[i] == nums2[i-1]){
                continue;
            }
            if(ls.find(nums2[i]) != ls.end()){
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};