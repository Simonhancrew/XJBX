#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            flytos[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK");
        backtracking(tickets.size(), 1, result);
        return result;
    }
private:
// unordered_map<出发城市, map<到达城市, 航班次数>> flytos
    unordered_map<string, map<string, int>> flytos;
    bool backtracking(int ticketNum, int index, vector<string>& result) {
        if (index == ticketNum + 1) {
            return true;
        }
        for (pair<const string, int>& flyto : flytos[result[result.size() - 1]]) {
            if (flyto.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
                result.push_back(flyto.first);
                flyto.second--;
                if (backtracking(ticketNum, index + 1, result)) return true;
                    result.pop_back();
                    flyto.second++;
                }
        }
        return false;
    }   
};