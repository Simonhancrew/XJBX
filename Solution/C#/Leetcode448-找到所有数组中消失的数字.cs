public class Solution {
    public IList<int> FindDisappearedNumbers(int[] nums) {
        int n = nums.Length;
        for(int i = 0;i < n;i++){
            int x = (nums[i] - 1) % n;
            nums[x] += n;
        }
        var result = new List<int>();
        for(int i = 0;i < n;i++){
            if(nums[i] <= n){
                result.Add (i+1);
            }
        }
        return result;
    }
}