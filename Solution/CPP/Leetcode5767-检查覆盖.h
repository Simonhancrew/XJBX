class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left;i <= right;i++){
            bool flage = false;
            for(auto ev:ranges){
                if(i >= ev[0] && i <= ev[1]) flage = true;
            }
            if(flage) continue;
            else return false;
        }      
        return true;
    }
};