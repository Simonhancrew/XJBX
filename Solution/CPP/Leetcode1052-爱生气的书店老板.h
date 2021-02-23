#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int init = 0;
        for(int i = 0;i < n;i++){
            init += grumpy[i] == 0?customers[i]:0;
        }
        int increase = 0;
        for(int i = 0;i < X;i++){
            increase += customers[i] * grumpy[i];
        }
        int maxincrease = increase;
        for(int i = X;i < n;i++){
            increase += customers[i] * grumpy[i] - grumpy[i - X] * customers[i - X];
            maxincrease = max(maxincrease,increase);
        }
        return init + maxincrease;
    }
};