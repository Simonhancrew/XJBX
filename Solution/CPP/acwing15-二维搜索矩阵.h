#include <vector>

using namespace std;

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty() || array[0].empty()) return false;
        int i = 0,j = array[0].size() - 1;
        //枚举右上角
        while(i < array.size() && j >= 0){
            if(array[i][j] == target) return true;
            else if (array[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};