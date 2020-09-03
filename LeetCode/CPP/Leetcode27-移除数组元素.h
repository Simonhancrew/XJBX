#include <vector>
using namespace std;
//暴力的方法，找到从后向前覆盖
class Solutin{
public:
    int removeElement(vector<int> &nums,int val){
        //数组的大小是可变的，所以必须记录一下最新的size，实时更新
        int size = nums.size();
        for(int i =0;i<size;i++){
            if(nums[i] == val){
                for(int j = i+1;j<size;j++){
                    nums[j-1] = nums[j];
                }
                --i;//下标i的数值都往前移了一位
                size--;
            }
        }
        return size;
    }
};
//数组和链表的经典双指针，一个for完成
//关键在于slowindex更新数组，fastIndex不等于slow的时候，fast跳过，index不记录
class Solution2 {
public:
    int removeElement(vector<int> &nums,int val){
        int slowIndex = 0;
        int size = nums.size();
        for(int fastIndex = 0;fastIndex < size;fastIndex++) {
            if(val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};