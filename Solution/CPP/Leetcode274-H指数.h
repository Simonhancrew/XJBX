#include <vector>
#include <algorithm>

using namespace std;
// 排序
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        int res = 0;
        for(int i = n;i >= 1;i--){
            // cout << citations[n - i] << '-' << i << endl;
            if(citations[n - i] >= i) {
                res = i;
                break;
            }   
        }
        return res;
    }
};