#include <vector>
using namespace std;
//先构造好三角，然后从上往下填值
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows == 0){
            return ans;
        }
        for(int i = 0;i < numRows;++i){
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for(int j = 1;j < i;++j){
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};