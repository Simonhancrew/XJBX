public class Solution {
    public int MaxTurbulenceSize(int[] arr) {
        int n = arr.Length;
        int ans = 1;
        int start = 0,end = 1;
        bool direction = false;
        while (end < n) {
            if (end == start + 1) {
                if (arr[end - 1] > arr[end]) {
                    direction = true;
                    ans = ans < 2 ?2:ans;
                }
                else if (arr[end - 1] < arr[end]) {
                    direction = false;                 
                    ans = ans < 2 ?2:ans;
                }
                else {
                    start++;
                }
                end++;
            }
            else {
                if ((arr[end - 1] > arr[end] && !direction) ||(arr[end - 1] < arr[end] && direction)) {
                    ans = ans < (end - start + 1)?end - start + 1:ans;
                    end++;
                    direction = !direction;
                }else {
                    start = end - 1;
                }
            }
        }
        return ans;
    }
}