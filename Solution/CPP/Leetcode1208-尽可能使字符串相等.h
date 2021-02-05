#include <string>
using namespace std;
//双指针
//维护一个窗口
//这种给定了一个代价数去求最大区间的一般都是滑动窗口
//已经遇见过的：    1 求最大区间值->双指针 2求窗口中值->两个堆，对半分，可能要删除的话需要维护一个删除表  
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int ans = 0;
        int len = s.size();
        int start = 0,end = 0;
        while(end < len){
            cost += abs(s[end] - t[end]);
            while(cost > maxCost){
                cost -= abs(s[start] - t[start]);
                start++;
            }
            ans = max(ans,end - start + 1);
            end++;
        }
        return ans;
    }
};