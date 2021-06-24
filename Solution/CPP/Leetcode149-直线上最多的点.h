#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;
        int res = 0;
        for(auto &p:points){
            int dup = 0,ver = 0;
            unordered_map<LD,int> cnt;
            for(auto &q:points){
                if(p == q) dup++;
                else if(p[0] == q[0]) ver++;
                else{
                    LD k = (LD)(q[1] - p[1]) / (q[0] - p[0]);
                    cnt[k]++;
                }
            }
            int cur = ver;
            for(auto [k,t]:cnt) cur = max(cur,t);
            res = max(cur + dup,res);
        }
        return res;
    }
};