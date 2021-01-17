#include <vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int offset_x = coordinates[0][0],offset_y = coordinates[0][1];
        int n = coordinates.size();
        for(int i = 0;i < n;i++){
            coordinates[i][0] -= offset_x;
            coordinates[i][1] -= offset_y;
        }
        int x = coordinates[1][0],y = coordinates[1][1];
        int A = y,B = -x;
        for(int i = 2;i < n;i++){
            if(A*coordinates[i][0] + B*coordinates[i][1] != 0){
                return false;
            }
        }
        return true;
    }
};