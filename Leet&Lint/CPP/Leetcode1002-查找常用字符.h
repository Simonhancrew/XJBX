#include <string>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<int> minfreq(26,INT_MAX);
        vector<int> freq(26);
        int n = A.size();
        for(const string& str:A){
            fill(freq.begin(),freq.end(),0);
            for(auto chr:str){
                ++freq[chr-'a'];
            }
            for(int i =0;i<26;i++){
                minfreq[i] = min(minfreq[i],freq[i]);
            }
        }
        for(int i = 0;i<26;i++){
            for(int j = 0;j<minfreq[i];j++){
                string a = "a";
                a[0]+=i;
                res.push_back(a);
            }
        }
        return res;
    }
};