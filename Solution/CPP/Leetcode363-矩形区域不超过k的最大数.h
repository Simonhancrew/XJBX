#include <set>
#include <vector>
using namespace std;
//暴力的思路是枚举矩阵的两个角的坐标，四次方会超时，考虑优化，先确定列，把他化成一维问题，
//之后，要找到这个区间，假定维护了一维前缀和，区间的前部一定是大于sum - k 的最小值，这样后面才是不大于k的值
//即可通过有序集合二分来找到这个确定的值
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;

        for (int lo = 0; lo < n; lo++) {
            vector<int> row(m, 0);
            for (int hi = lo; hi < n; hi++) {
                set<int> pre;
                int sum = 0;

                pre.insert(0);
                for (int i = 0; i < m; i++) {
                    row[i] += matrix[i][hi];
                    sum += row[i];
                    auto it = pre.lower_bound(sum - k);
                    if (it != pre.end())
                        ans = max(ans, sum - *it);
                    pre.insert(sum);
                }
            }
        }

        return ans;
    }
};