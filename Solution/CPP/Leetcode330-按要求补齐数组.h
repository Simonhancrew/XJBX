#include <vector>
using namespace std;
//假设当前能覆盖的是1-（x-1）
//则加入x之后能覆盖到1-（2x-1）
//最后要求覆盖到n，我们设置一个最小覆盖范围，不断的去更新他
//直到覆盖到了n
//开始设置x为1，开始1-(x-1)是空的,如果第一个能覆盖，下一个能覆盖的范围就是nums[index] + x -1
//反之，如果不能覆盖的话，说明他只能覆盖到x-1，我们要补充的数最少，不如贪心的补充x，
//那么他下一次就能覆盖到2x-1，这个时候再去看看能不能覆盖
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        int index = 0;
        int x = 1;//当前被覆盖的数，开始1-（x-1）是一个空区间
        while(x <= n){
            //找到当前没有被覆盖的最小的数
            if(index < nums.size() && nums[index] <= x){
                x += nums[index];
                index++;
            }else{
                //当前覆盖了1-(x-1),增加x就能覆盖到2x-1
                //添加x，index不变
                res++;
                x <<= 1;
            }
        }
        return res;
    }
};