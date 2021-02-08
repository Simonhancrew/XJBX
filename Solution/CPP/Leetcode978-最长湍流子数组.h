#include <vector>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        bool direction;
        int start = 0, end = 1;
        while (end < n) {
            if (end == start + 1) {
                if (arr[end - 1] > arr[end]) {
                    direction = 1;
                    ans = max(ans, 2);
                }
                else if (arr[end - 1] < arr[end]) {
                    direction = 0;                 
                    ans = max(ans, 2);
                }
                else {
                    start++;
                }
                end++;
            }
            else {
                if ((arr[end - 1] > arr[end] && !direction) ||(arr[end - 1] < arr[end] && direction)) {
                    ans = max(ans, end - start + 1);
                    end++;
                    direction = !direction;
                }else {
                    start = end - 1;
                }
            }
        }
        return ans;
    }
};