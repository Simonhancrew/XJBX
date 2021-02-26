#pragma once
#include <vector>
using namespace std;
class BinarySearch {
//数组要求有序
public:
	bool binarySearch(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin < end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else if (nums[mid] > target) {
				end = mid-1;
			}
			else if (nums[mid] < target) {
				begin = mid + 1;
			}
		}
		return false;
	}
	bool binarySearch(vector<int>& nums, int target,int begin,int end) {
		int mid = begin + (end - begin) / 2;
		if (begin > end) {
			return false;
		}
		if (target == nums[mid]) {
			return true;
		}
		else if (target > nums[mid]) {
			binarySearch(nums, target, mid+1, end);
		}
		else if (target < nums[mid]) {
			binarySearch(nums, target, begin, mid-1);
		}
	}
};


/*整数2分的模板

bool check(int x) {} // 检查x是否满足某种性质

//其实很简单，先写出 mid = l + r >> 1，之后考虑l == r，此时mid会等于l，如果如果选择l == mid 会造成持续死循环
// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
*/

//二分不仅仅可以去对单调的数组使用，还可以对与满足某种区间性质的容器去使用
#include <iostream>
const int N = 1e5 + 10;
int n,m;
int q[N];

int main(){
	//ios::sync_with_stdio(false);开了的话就不能混用cin和printf两种输入输出
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&q[i]);
    
    while(m--){
        int x;
        scanf("%d",&x);
        
        int l = 0,r = n -1;
        while(l < r){
            int mid = r + l + 1 >> 1;
            //check里放的是性质，此时我找的性质是当前的数都不大于x，所以是右端点
            if(q[mid] <= x) l = mid;
			//因为mid此时的数比x大，不行，r需要为 mid-1
            else r =  mid - 1;
        } 
        if (q[l] != x) cout <<"-1 -1"<<endl;
		//下面的部分又是一个二分
        else{
            int l1 = 0,r1 = n - 1;
            while(l1 < r1){
                int mid = l1 + r1>> 1;
                if(q[mid] >= x) r1 = mid;
                else l1 = mid + 1;
            }
            cout << l1 << ' '<< l << endl; 
        }
    }
    return 0;
}