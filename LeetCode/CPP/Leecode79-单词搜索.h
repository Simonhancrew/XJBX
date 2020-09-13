#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        //记录一个访问过的数组，防止出现重复
        vector<vector<int>> visited(h, vector<int>(w));
        //遍历每一个位置，注意在遍历一个位置之后将visited置为0
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                //对于每一个位置如果能直接结束就回true
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    //check每一个位置的word[index]是否能和board[h][w]匹配
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int index) {
        if (board[i][j] != s[index]) {
            return false;
        } else if (index == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, index + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};