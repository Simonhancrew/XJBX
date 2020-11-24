#include <vector>
#include <algorithm>
using namespace std;
//排序两个数组。
//从饼干和孩子的末尾开始，大饼干优先喂饱大胃口的孩子
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int index = s.size() - 1;
        for(int i = g.size() - 1;i >= 0;--i){
            if(index >= 0 && s[index] >= g[i]){
                index--;
                res++; 
            }
        }
        return res;
    }
};
//反向操作，小的喂刚刚合适得
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int index = 0;
        for(int i = 0;i < s.size();++i){
            if(index < g.size() && g[index] <= s[i]){
                index++;
                res++; 
            }
        }
        return res;
    }
};