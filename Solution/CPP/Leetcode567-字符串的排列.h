#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int patternsize = s1.size();
        int n = s2.size();
        if(n < patternsize){
            return false;
        }
        vector<int> nums(26,0);
        for(auto &s:s1){
            nums[s - 'a']++;
        }
        int start = 0,end = patternsize - 1;
        while(end < n){
            if(checksame(nums,s2,start,end)){
                return true;
            }
            start++;
            end++;
        }
        return false;
    }
    bool checksame(vector<int> nums,string &s2,int start,int end){
        for(int i = start;i <= end;i++){
            nums[s2[i] - 'a']--;
            if(nums[s2[i] - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};