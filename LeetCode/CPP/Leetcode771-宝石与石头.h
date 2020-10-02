#include <string>
#include <unordered_set>
using namespace std;
//m*n
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for(auto s:S){
            res += getType(s,J);
        }
        return res;
    }
    int getType(char chr,string &J) {
        for(auto str:J){
            if(chr == str){
                return 1;
            }
        }
        return 0;
    }
};

//m+n
class Solution2 {
public:
    int numJewelsInStones(string J, string S) {
        int jewelsCount = 0;
        unordered_set<char> jewelsSet;
        int jewelsLength = J.length(), stonesLength = S.length();
        for (int i = 0; i < jewelsLength; i++) {
            char jewel = J[i];
            jewelsSet.insert(jewel);
        }
        for (int i = 0; i < stonesLength; i++) {
            char stone = S[i];
            if (jewelsSet.count(stone)) {
                jewelsCount++;
            }
        }
        return jewelsCount;
    }
};
