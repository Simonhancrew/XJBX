#include <vector>

using namespace std;

class Solution {
public:
    vector<int> glb;
    int length;
    int hIndex(vector<int>& citations) {
        glb = citations;
        length = citations.size();
        int l = 0,r = length;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    bool check(int idx){
        return glb[length - idx] >= idx;
    }
};