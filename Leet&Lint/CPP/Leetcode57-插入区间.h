#include <vector>
using namespace std;
//对和新区间有交叉的区间求一个并集
//然后加入区间
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,vector<int> &newInterval){
        int lhs = newInterval[0],rhs = newInterval[1];
        //新构建的区间是否已经放置到了结果向量中
        bool placed = false;
        vector<vector<int>> res;
        for(const auto& interval:intervals){
            //如果新的区间的左侧已经比要插入的区间的右侧大了
            if(interval[0] > rhs){
                //且要插入的区间没有放置
                if(!placed){
                    res.push_back({lhs,rhs});
                    placed = true;
                }
                //放置右侧的区间
                res.push_back(interval);
            }else if(interval[1] < lhs){
                //如果当前区间的右侧比新加入区间的左侧节点还小
                //没有交集，直接加入结果
                res.push_back(interval);
            }else{
                //对有交集的区间，求一个并集
                lhs = min(interval[0],lhs);
                rhs = max(interval[1],rhs);
            }
        }
        //此时，如果新加入的区间是最后一个区间
        if(!placed){
            res.push_back({lhs,rhs});
            placed = true;
        }
        return res;
    }
};