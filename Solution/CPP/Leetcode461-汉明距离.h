class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 30;i >= 0;i--){
            int xi = (x >> i) & 1;
            int yi = (y >> i) & 1;
            if(xi != yi) ans++;
        }
        return ans;
    }
};


//lowbit

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int s = x ^ y;
        while(s){
            s -= (s &(-s));
            ans ++;
        }
        return ans;
    }
};