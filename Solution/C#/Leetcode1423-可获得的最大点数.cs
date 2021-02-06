public class Solution {
    public int MaxScore(int[] cardPoints, int k) {
        int n = cardPoints.Length;
        int windowsize = n - k;
        int sum = 0;
        for(int i = 0;i < windowsize;i++){
            sum += cardPoints[i];
        }
        int minsum = sum;
        for(int i = windowsize;i < n;i++){
            sum += cardPoints[i] - cardPoints[i - windowsize];
            minsum = minsum < sum ? minsum:sum;
        }
        int total = cardPoints.Sum();
        return total - minsum;
    }
}