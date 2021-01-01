#include <vector>
using namespace std;
//最朴素的想法就是枚举每一个的高度，然后看看他的宽度
//或者枚举一个宽度，然后枚举他的高度
//超时了，于是选择用空间换时间
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i = 0;i < n;++i){
            int local = heights[i];
            int left = i,right = i;
            while(left - 1 >= 0 && heights[left - 1] >= local){
                left--;
            }
            while(right + 1 < n && heights[right + 1] >= local){
                right++;
            }
            ans = max(ans,(right - left + 1) * local);
        }
        return ans;
    }
};

//左神之前讲过，单调栈对找左边第一个小于他的元素很快，本题利用单调栈
//空间换时间的方式
#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        //先枚举每个点，左边比他小的
        stack<int> stk;
        for(int i = 0;i < n;++i){
            while(!stk.empty() && heights[i] <= heights[stk.top()]){
                stk.pop();
            }
            left[i] = stk.empty()?-1:stk.top();
            stk.push(i);
        }
        stk =  stack<int> ();
        for(int i = n -1;i >= 0;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            right[i] = stk.empty()?n:stk.top();
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0;i < n;++i){
            ans = max(ans,(right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};