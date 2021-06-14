class Solution {
public:
    int guessNumber(int n) {
        int l = 1,r = n;
        while(l < r){
            int mid = l + (r - l>> 1);
            if(guess(mid) > 0) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};