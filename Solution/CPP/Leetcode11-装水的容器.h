#include <vector>
#include <algorithm>
using namespace std;
//双指针
//头尾，如果一端小，移动小端
//因为木桶短板，装水是看最短的
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1;
        int maxA = 0;
        while(i < j){
            int cur = min(height[i],height[j]) * (j - i);
            maxA = std::max(maxA,cur);
            if(height[i] < height[j]) {
                ++i;
            }else{
                --j;
            }
        }
        return maxA;
    }
};