class Solution {
public:
    //利用哈希，没有用到数组有序的信息O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        for(int i = 0;i<numbers.size();i++){
            int findnext = target - numbers[i];
            map[findnext] = i;
        }
        for(int i = 0;i<numbers.size();i++){
            auto pos = map.find(numbers[i]);
            if(pos != map.end()){
                return vector<int> {i+1,pos->second+1};
            }
        }
        return vector<int> ();
    }

    //二分查找target-nums[i]
     vector<int> twoSumBinarySearch(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
    //双指针，和小于则右指针右移，和大于则左指针左移
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};