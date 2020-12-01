#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
//认识到这题这需要在整个的递归树上找到一个最优解即可，所以可以选择用bool的返回值去加速
//参考Leetcode112题，不需要去遍历整棵树的话其实就不需要返回值
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            //flytos[vec[0]] -- map<string,int>
            //flytos[vec[o]][vec[1]] -- int
            flytos[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK");
        backtracking(tickets.size(), 1, result);
        return result;
    }
private:
    // unordered_map<出发城市, map<到达城市, 航班次数>> flytos
    //第二个选用map就可以顺序记录城市，航班次数。
    //选用set删除会导致迭代器失效
    //bool函数只要结束，result必然是答案
    unordered_map<string, map<string, int>> flytos;
    bool backtracking(int ticketNum, int index, vector<string>& result) {
        //如果到了最后一个城市的位置，入栈。可以套回溯模板
        //到达的机场数是所有的航班数+1的话
        if (index == ticketNum + 1) {
            return true;
        }
        //flyto,result最后一个位置的城市可以去的<城市，航班次数>
        for (pair<const string, int>& flyto : flytos[result[result.size() - 1]]) {
            if (flyto.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
                result.push_back(flyto.first);
                flyto.second--;
                //继续下的的过程中找到了这条路，直接返回
                if (backtracking(ticketNum, index + 1, result)) return true;
                //没有找到这条路的话popback，回溯
                result.pop_back();
                flyto.second++;
            }
        }
        return false;
    }   
};