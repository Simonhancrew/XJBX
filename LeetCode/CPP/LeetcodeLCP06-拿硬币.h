#include <vector>
using namespace std;
class Solution {
public:
    int minCount(vector<int>& coins) {
        int ret = 0;
        for(auto coin:coins){
            ret += coin / 2;
            ret += coin % 2;
        }
        return ret;
    }
};