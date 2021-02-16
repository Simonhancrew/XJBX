public class Solution {
    public int ArrayPairSum(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length;
        int ans = 0;
        for(int i = 0;i < n;i+=2){
            ans += nums[i];
        }
        return ans;
    }
}