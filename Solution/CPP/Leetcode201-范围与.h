
//因为连续，所以一定可以找到公共前缀。前缀后的是呈一个轮回变化的
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};
//Brian Kernighan 算法（去除最右边的1）
//n & (n-1)就可以去除n二进制串中最右边的1
//只要我们连续的去除n最右边的1，直到n不大于m的时候就完成了公共前缀的搜索
class Solution2{
public:
    int rangeBitwiseAnd(int m,int n){
        while(m<n){
            n &= (n-1); 
        }
        return n;
    }
};