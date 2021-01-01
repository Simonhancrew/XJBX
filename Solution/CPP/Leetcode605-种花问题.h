#include <vector>
using namespace std;
//从前往后遍历，维护一个cont，能种花的总数，如果count大于n，返回true
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int end = flowerbed.size();
        for (int i = 0;i < end;i++){
            //注意边界的判断
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == end - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                count++;
            }
        }
        return count > n;
    }
};