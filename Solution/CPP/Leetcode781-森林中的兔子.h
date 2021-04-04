#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if(!n) return 0;
        int res = 0;
        unordered_map<int,int> hash;
        hash[answers[0]] ++;
        res = answers[0] + 1;
        for(int i = 1;i < n;i++){
            if(hash.count(answers[i])){
                if(answers[i] == 0){
                    res++;
                }else if(hash[answers[i]] < answers[i] + 1){
                    hash[answers[i]] ++;
                }else{
                    hash[answers[i]] = 1;
                    res += answers[i] + 1;
                }
            }else{
                hash[answers[i]]++;
                res += answers[i] + 1;
            }
        }
        return res;
    }
};