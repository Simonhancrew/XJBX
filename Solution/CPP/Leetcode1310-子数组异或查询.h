#include <vector>
using namespace std;
//前缀和
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        arr.push_back(0);
        for(int i = 1;i <= n;i++){
            arr[i] ^= arr[i - 1];
        }
        arr.insert(arr.begin(),0);
        vector<int> res;
        for(auto query:queries){
            int tmp = arr[query[1] + 1] ^ arr[query[0]];
            res.push_back(tmp);
        }
        return res;
    }
};