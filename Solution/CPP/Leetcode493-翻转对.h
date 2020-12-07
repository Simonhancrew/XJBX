#include <vector>
using namespace std;
//形如i，在i的一侧找一个j,nums[j]值满足关系
//找到区间和问题,分治
//超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        for(int i = 0;i < nums.size();++i){
            for(int j = i + 1;j < nums.size();++j){
                if((long long)nums[i] > (long long) 2 * nums[j]){
                    ret++;
                }
            }
        }
        return ret;
    }
};

//基于归并排序的方法
//本题和区间和很像，都是求某个元素左侧符合要求的元素对于i,nums[j] > 2*nums[i],j位于i的左侧
//还是分治的思想，假设两个数组，每个数组都知道了反转对的个数
//且这两个数组是有序的，剩下的反转对就是端点在分别在两个数组中的
//两个数组有序的话就可以顺序的去处理对的个数
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        return reverseRecursive(nums,0,nums.size() - 1);
    }
private:
    int reverseRecursive(vector<int> &nums,int left,int right){
        if(left == right){
            return 0;
        }
        //左边的翻转对和右边的翻转对
        int mid = left + (right - left) / 2;
        int n1 = reverseRecursive(nums,left,mid);
        int n2 = reverseRecursive(nums,mid + 1,right);
        int ret = n1 + n2;
        //找ij分别在两端的
        int i = left;
        int j = mid + 1;
        while (i <= mid){
            while(j <= right && (long long) nums[i] > (long long)2 * nums[j]){
                j++;
            }
            ret += (j - (mid + 1));
            ++i;
        }
        //merge两个数组 
        vector<int> sorted(right - left + 1);
        int p = 0;
        int p1 = left,p2 = mid + 1;
        while(p1 <= mid ||p2 <= right){
            if(p1 > mid){
                sorted[p++] = nums[p2++];
            }else if(p2 > right){
                sorted[p++] = nums[p1++];
            }else{
                if(nums[p1] > nums[p2]){
                    sorted[p++] = nums[p2++];
                }else{
                    sorted[p++] = nums[p1++];
                }
            }
        }
        //将有序的数组赋值回原数组
        //这一步看递归栈的话，最后一次其实没有必要
        //但是在栈到顶那次之后，有序的数组可以加速顺序的迭代查找
        //所以不要忘记这一步
        for(int i = 0;i < sorted.size();++i){
            nums[left + i] = sorted[i];
        }
        return ret;
    }
};

//还有树状数组和线段树和二叉搜索树的方法，
//not by me
class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int d) {
        while (x <= n) {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<long long> allNumbers;
        for (int x : nums) {
            allNumbers.insert(x);
            allNumbers.insert((long long)x * 2);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers) {
            values[x] = ++idx;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); i++) {
            int left = values[(long long)nums[i] * 2], right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.update(values[nums[i]], 1);
        }
        return ret;
    }
};
