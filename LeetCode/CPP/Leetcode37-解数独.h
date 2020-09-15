#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board){
        valid = false;
        memset(line,false,sizeof(line));
        memset(column,false,sizeof(column));
        memset(area,false,sizeof(area));
        //填充每一个确认数组
        for(int i =0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    //找到空格的位置
                    spaces.push_back({i,j});
                }else{
                    int digit = board[i][j]-'0'-1;//映射到数组
                    //标记这一行，列，area已经出现过的数字
                    line[i][digit] = column[j][digit] = area[i/3][j/3][digit] = true;
                }
            }
        }
        DFS(board,0);
    }
private:
    bool line[9][9];//行的1-9
    bool column[9][9];//列的1-9
    bool area[3][3][9];//每个area格子的1-9
    bool valid;//结果是否冲突，需要一个结束的标志
    vector<pair<int,int>> spaces;
    void DFS(vector<vector<char>> &board,int pos){
        //所有位置都填充完成，且没有冲突，将valid置为1，找到了题目认为的唯一的答案，之后不必再执行下去
        if(pos == spaces.size()){
            valid = true;
            return;
        }
        pair<int,int> position = spaces[pos];
        int i = position.first,j = position.second;
        //让该空格位置替换为1-9这几个数字，去深搜之后回溯。如果某次之前出现了正确答案，就不再执行下去
        for(int digit = 0;digit<9 && !valid;digit++){
            if(!line[i][digit]&&!column[j][digit]&&!area[i/3][j/3][digit]){
                board[i][j] = digit+1+'0';
                line[i][digit] = true,column[j][digit] = true,area[i/3][j/3][digit] = true;
                DFS(board,pos+1);
                line[i][digit] = false,column[j][digit] = false,area[i/3][j/3][digit] = false;
            }
        }
    }
}; 