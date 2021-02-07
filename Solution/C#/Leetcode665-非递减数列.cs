public class Solution {
    public bool CheckPossibility(int[] nums) {
        int n = nums.Length;
        int cnt = 0;
        for(int i = 0;i < n-1;i++){
            int x = nums[i],y = nums[i+1];
            if(x > y){
                cnt++;
                if (cnt > 1){
                    return false;
                }
                if(i > 0 && nums[i+1] < nums[i - 1]){
                    nums[i+1] = nums[i]; 
                }
            }
        }
        return true;
    }
}