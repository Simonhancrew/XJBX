#include <vector>
#include <stack>
//单调栈模板
//从后向前
using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int> &T){
        vector<int> res(T.size());
        stack<int> s;
        for(int i = T.size();i >= 0;--i){
            while(!s.empty() && T[s.top()] <= T[i]){
                s.pop();
            }
            res[i] = s.empty()?-1:(s.top()-i);
            s.push(i);
        }
        //推入索引
        return res;
    }
};