#include <vector>
#include <unordered_set>
using namespace std;
//超时
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        int n = A.size();
        unordered_set<int> inset;
        for (int i = 0; i < n - K + 1; i++) {
            inset.clear();
            for (int j = i; j < n; j++) {
                if (inset.count(A[j]) == 0 && inset.size() < K) {
                    inset.insert(A[j]);
                }
                else if (inset.count(A[j]) == 0 && inset.size() == K) {
                    inset.clear();
                    break;
                }
                if (inset.size() == K) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

//双指针窗口
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0;
        int n = A.size();
        //针对每个右端点，他的左端一定是相邻的
        //这里维护两个窗口数组，一个最后的大小是K，一个是K-1
        //则start1 - start2就是一组合格的左端点值
        vector<int> nums1(n+1),nums2(n+1);
        int total1 = 0,total2 = 0;
        int end = 0,start1 = 0,start2 = 0;
        while(end < n){
            if(!nums1[A[end]]){
                total1++;
            }
            nums1[A[end]]++;
            if(!nums2[A[end]]){
                total2++;
            }
            nums2[A[end]]++;
            while(total1 > K){
                nums1[A[start1]]--;
                if(!nums1[A[start1]]){
                    total1--;
                }
                start1++;   
            }
            while(total2 > K - 1){
                nums2[A[start2]]--;
                if(!nums2[A[start2]]){
                    total2--;
                }
                start2++;
            }
            ans += start2 - start1;
            end++;
        }
        return ans;
    }
};