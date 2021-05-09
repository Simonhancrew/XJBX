class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int res = 0,cnt = 0;
        for(int i = 1950;i < 2050;i++){
            int cur = 0;
            for(auto log:logs){
                if(i >= log[0] && i < log[1]){
                    cur++;
                }
                if(cur > cnt) res = i,cnt = cur;
            }
        }
        return res;
    }
};