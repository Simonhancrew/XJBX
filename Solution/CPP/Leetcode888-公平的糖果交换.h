#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int suma = 0,sumb = 0;
        for(auto a:A){
            suma += a;
            mp[a]++;
        }
        for(auto b:B){
            sumb += b;
        }
        int want = (suma - sumb) / 2;
        vector<int> ans;
        for(int i = 0;i < B.size();i++){
            if(mp.count(want + B[i])){
                ans.push_back(want + B[i]);
                ans.push_back(B[i]);
                return ans;
            }
        }
        return {};
    }
};