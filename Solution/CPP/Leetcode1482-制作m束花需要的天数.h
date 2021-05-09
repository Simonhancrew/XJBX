#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int m,k;
    vector<int> bloomDay;
    int minDays(vector<int>& bloomDay, int m, int k) {
        this->bloomDay = bloomDay,this->k = k,this->m = m;
        int l = *min_element(bloomDay.begin(),bloomDay.end()),r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        if(!check(l)) l = -1;
        return l;
    }
    bool check(int day){
        int res = 0;
        int i = 0;
        while(i < bloomDay.size()){
            if(bloomDay[i] <= day){
                int cnt = 1;
                while(i + 1 < bloomDay.size() && bloomDay[i + 1] <= day && cnt != k){
                    cnt ++;
                    i++;
                }
                if(cnt == k) res ++;
                if(res == m) return true;
            }
            i++;
        }
        return false;
    }
};