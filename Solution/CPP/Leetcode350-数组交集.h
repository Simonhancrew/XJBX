class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> m;
        for (int num:nums1){
            ++m[num];
        }
        vector<int> vec;
        for(int num:nums2){
            if(m.count(num)){
                vec.push_back(num);
                --m[num];
                if(m[num]==0){
                    m.erase(num);
                }
            }
        }
        return vec;
    }
};