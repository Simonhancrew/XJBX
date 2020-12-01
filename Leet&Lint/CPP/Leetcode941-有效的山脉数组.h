//注意处理数组不越界
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) {
            return false;
        }
        //找山峰
        int index = 0;
        int n = A.size();
        while(index + 1 < n && A[index + 1] > A[index]){
            ++index;
        }
        if(index == 0 ||index == n-1){
            return false;
        }
        //找山脚
        while(index + 1 < n && A[index] > A[index + 1]){
            ++index;
        }
        return index == A.size()-1;
    }
};