#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num:nums){
            if(map.find(num) != map.end()){
                return true;
            }
            map[num]++;
        }
        return false;
    }
};