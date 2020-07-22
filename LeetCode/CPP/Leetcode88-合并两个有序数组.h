//双指针，用了额外数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec;
        int i = 0,j = 0;
        for(;i<m&&j<n;){
            if(nums1[i]>=nums2[j]){
                vec.push_back(nums2[j]);
                j++;
            }else{
                vec.push_back(nums1[i]);
                i++;
            }
        }
        while(j<n){
            vec.push_back(nums2[j++]);
        }
        while(i<m){
            vec.push_back(nums1[i++]);
        }
        nums1 = vec;
    }
};
//双指针，不用额外空间。
class solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int p1 = m-1;
        int p2 = n-1;
        int p = m+n-1;
        while ((p1 >= 0) && (p2 >= 0)){
            nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
        }
        for(int i = 0;i<p2+1;i++){
            nums1[i] = nums2[i];
        }
    }

};

//令我惊讶的是两种方法的空间复杂度在oj上差不多。