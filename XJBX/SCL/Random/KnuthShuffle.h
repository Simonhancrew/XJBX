#include <random>
#include <vector>
#include <algorithm>
using namespace std;
//1/n
//(n-1)/n * 1/n-1 = 1/n
void KnuthShuffle(vector<int> &nums){
    int n = nums.size();
    random_device r;
    std::mt19937 gen(r);
    for(int i = n-1;i>=0;i--){
        uniform_int_distribution<int> uniform(0,i);
        swap(nums[i],nums[uniform(gen)]);
    }
}