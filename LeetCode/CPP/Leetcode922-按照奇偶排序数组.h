#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int i = 0;
        while(i < n){
            if(i % 2 == A[i] % 2){
                i++;
            }else{
                //奇数位上的偶数
                if(i % 2 == 1 && A[i] % 2 == 0){
                    int j = i + 1;
                    //偶数位的奇数
                    while(j % 2 == 1||(j % 2 == 0 && A[j] % 2 == 0)){
                        j++;
                    }
                    swap(A[i],A[j]);
                    ++i;
                }else{
                    //偶数位的奇数
                    int j = i + 1;
                    //找奇数位的偶数
                    while(j % 2 == 0||(j % 2 == 1 && A[j] % 2 == 1)){
                        j++;
                    }
                    swap(A[i],A[j]);
                    ++i;
                }
            }
        }
        return A;
    }
};
//两次遍历，分别放置
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);

        int i = 0;
        for (int x: A) {
            if (x % 2 == 0) {
                ans[i] = x;
                i += 2;
            }
        }
        i = 1;
        for (int x: A) {
            if (x % 2 == 1) {
                ans[i] = x;
                i += 2;
            }
        }
        return ans;
    }
};

//双指针，偶数位，奇数位
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }   
        return A;
    }
};
