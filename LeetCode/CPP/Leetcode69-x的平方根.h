//二分搜索找到这个值
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
//牛顿迭代法求函数为0时的解
//xn+1 = xn - F(xn)/(f(xn)的导数)
//x = sqrt(n)->x*x = n-> f(x) = x*x - n = 0
class Solution {
public:
    int mySqrt(int n){
        long x = n;
        while(x*x > n){
            x = (x + n/x)/2;
        }
        return (int)x;
    }
};