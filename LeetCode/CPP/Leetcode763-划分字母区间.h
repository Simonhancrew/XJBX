#include <string>
#include <vector>
using namespace std;
//1 一个字母第一次出现和最后一次出现一定在一个片段
//2 贪心的选择最小的结束下标片段
class Solution {
public:
    vector<int> partitionLabels(string S) {
        static int last[26];
        int n = S.size();
        //拿到每个字母最后出现的位置
        for(int i = 0;i < n;++i){
            last[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        //贪心的找到最边缘的数字
        for(int i = 0;i < n;++i){
            end = max(end,last[S[i] - 'a']);
            if(i == end){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};