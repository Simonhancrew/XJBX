#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //拿到二级制值
    int getB(int x){
        int res = 0;
        while(x){
            res += x%2;
            x = x/2;
        }
        return res;
    }
    //因为最多10000个数，开一个bit数组记录映射关系就可以了
    vector<int> sortByBits(vector<int>& arr) {
        //最多1000个数
        vector<int> bits(10001,0);
        for(auto num:arr){
            bits[num] = getB(num);
        }
        //利用sort排序，规则定义为二级制下的1个数
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if(bits[x] < bits[y]){
                return true;
            }
            if(bits[x] > bits[y]){
                return false;
            }
            return x < y;
        });
        return arr;
    }
};