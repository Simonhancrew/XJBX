#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        // for(auto num:chalk) sum += num;
        int sum = accumulate(chalk.begin(),chalk.end(),0);
        while(sum <= k) k -= sum; 
        for(int i = 0;;i++){
            int tr = i % chalk.size();
            if(k < chalk[tr]) return tr;
            else{
                k -= chalk[tr];
            }
        }
        return 0;
    }
};