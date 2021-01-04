class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }else{
            return fib(n - 1)+fib(n-2); 
        }
    }
};

class Solution {
public:
    int fib(int n){
        if(n < 2){
            return n;
        }
        int p = 0,q= 0,r = 1;
        for(int i = 2;i <= n;i++){
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};