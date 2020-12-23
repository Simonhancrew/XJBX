#include <string>
#include <vector>
using namespace std;
//两遍哈希，第二遍找到了唯一就直接输出
class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> mp(26,{-1,0});
        int len = s.size();
        for(int i = 0;i < len;++i){
            if(mp[s[i] - 'a'].first != -1){
                mp[s[i] - 'a'].second++;
            }else{
                mp[s[i] - 'a'].first = i;
                mp[s[i] - 'a'].second = 1;
            }
        }
        for(int i = 0;i < len;i++){
            if(mp[s[i] - 'a'].second == 1){
                return i;
            }
        }
        return -1;
    }
};