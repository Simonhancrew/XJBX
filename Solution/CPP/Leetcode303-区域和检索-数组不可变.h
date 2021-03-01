#include <vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        array = nums;
    }   
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int start = i;start <= j;start++){
            sum += array[start];
        }
        return sum;
    }
private:
    vector<int> array;
};

//考虑前缀和
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        array.resize(n + 1);
        for(int i = 0;i < n;i++){
            array[i + 1] = array[i] + nums[i];
        }
    }   
    
    int sumRange(int i, int j) {
        return array[j + 1] - array[i];        
    }
private:
    vector<int> array;
};
