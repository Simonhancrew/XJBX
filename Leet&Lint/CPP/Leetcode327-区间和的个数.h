#include <vector>
using namespace std;
//构造一个前缀和数组，然后区间的对数等价于该数组两者之差在lowe和upper之内的总数
//本体归并的求解，分成两个有序数组
//对第一个数组中的每一个数，找到第二个数组中，符合要求的区间（令第一个数组中的数和第二个数组中的数构成数对）。
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long add = 0;
        //前缀数组
        vector<long> sum;
        sum.push_back(0);
        for(auto& v: nums) {
            add += v;
            sum.push_back(add);
        }
        return count(sum, lower, upper, 0, sum.size() - 1);
    }
private:
    //注意sum传reference，需要修改排序
    int count(vector<long>& sum, int lower, int upper, int left, int right) {
        //递归结束，单一值，无法构成对
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int n1 = count(sum, lower, upper, left, mid);
        int n2 = count(sum, lower, upper, mid + 1, right);
        int ret = n1 + n2;

        //递归回调之后，两个数组已经有序
        // 统计下标对的数量
        //第一个数组的index
        int i = left;
        //第二个数组，配合第一个数组的nums[i]符合条件的区间
        int l = mid + 1;
        int r = mid + 1;
        //找到这个区间，总的数对数就是r-l
        while (i <= mid) {
            while (l <= right && sum[l] - sum[i] < lower) l++;
            while (r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        //简单的merge
        //只要有一个数组还能往里填数
        while (p1 <= mid || p2 <= right) {
            //p2之后还有数
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            } else if (p2 > right) {
                //p1之后还有数
                sorted[p++] = sum[p1++];
            } else {
                //都有，谁小谁先入
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                } else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        //改原数组
        for (int i = 0; i < sorted.size(); i++) {
            sum[left + i] = sorted[i];
        }
        return ret;
    }
};