#include <vector>
using namespace std;
//还是不断地扩大能访问的范围
//每次走过当前能访问的最大范围，步数+1
//当范围第一次扩大到终点时结束，返回此时的步数
//coding上要注意，如果当前覆盖最远距离下标就是是集合终点，步数不用加一，因为不能再往后走了。
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        //当前覆盖范围
        int curArea = 0;
        //下一次覆盖范围
        int nextArea = 0;
        //步数
        int ans = 0;
        for(int i = 0;i < nums.size();++i){
            nextArea = max(nums[i] + i,nextArea);
            if(i == curArea){
                if(curArea != nums.size() - 1){
                    ans++;
                    curArea = nextArea;
                    if(nextArea >= nums.size() - 1) 
                        break;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};

//终点一定可达
//达到倒数第二个坐标之后如果还在范围内，最后一个坐标也一定在范围内
//到达倒数第二个之后范围到达边缘的话，最后一个的ans++
//控制移动下标i只移动到nums.size() - 2的位置，所以移动下标只要遇到当前覆盖最远距离的下标，直接步数加一，不用考虑别的了
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;    // 当前覆盖的最远距离下标
        int ans = 0;            // 记录走的最大步数 
        int nextDistance = 0;   // 下一步覆盖的最远距离下标 
        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};