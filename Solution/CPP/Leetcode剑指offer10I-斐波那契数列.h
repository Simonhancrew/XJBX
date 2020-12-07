class Solution {
public:
    int fib(int n) {
        int x = 0,y = 1;
        static int cons = 1000000007;
        for(int i = 0;i < n;++i){
            int tmp = x;
            x = y;
            y = (tmp + y) % cons;
        }
        return x % cons;
    }
};