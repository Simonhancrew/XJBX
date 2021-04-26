class Solution {
public:
    int days;
    vector<int> wei;
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = accumulate(weights.begin(),weights.end(),0);
        days = D;
        wei = weights;
        int l = *max_element(weights.begin(),weights.end()), r = sum;
        while(l < r){
            int mid = l + r >> 1;
            if(possible(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool possible(int load){
        int cur = 0,res = 0;
        for(int i = 0;i < wei.size();i++){
            if(cur != 0 && cur + wei[i] <= load) cur += wei[i];
            else{
                cur = wei[i];
                res ++;
            }
        }
        if(res <= days) return true;
        return false;
    }
};