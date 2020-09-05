#include <string>
#include <vector>
using namespace std;
//通过数学方法不断的缩小范围，直到落入正确的解答范围中
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i - 1];
        }
        k--;
        string ans;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int order = k / factorial[n - i];
            ans.push_back(nums[order] + '0');
            //从数组中删除这个数
            for (int j = order; j < n - i; j++) {
                nums[j] = nums[j + 1];
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};
