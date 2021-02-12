#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex + 1);
        if(rowIndex == 0){
            return vector<int> {1};
        }
        for(int i = 0; i < rowIndex + 1;i++){
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1;j < i;j++){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans[rowIndex];
    }
};


//只用两个数组
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre,cur;
        for(int i = 0; i < rowIndex + 1;i++){
            cur.resize(i+1,0);
            cur[0] = cur[i] = 1;
            for(int j = 1;j < i;j++){
                cur[j] = pre[j] + pre[j-1];
            }
            pre = cur;
        }
        return cur;
    }
};