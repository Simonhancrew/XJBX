//输入一个数组，输出数组。新数组值为原数组当前下标之后第一个比当前值大的下标。
//[73, 74, 75, 71, 69, 72, 76, 73]->[1, 1, 4, 2, 1, 1, 0, 0]
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> P(n);
        stack<int> s;
        for (int i=0;i<n;i++){
           while(!s.empty()&&T[i]>T[s.top()]){
               int m =i - s.top();
               P[s.top()] = m;
               s.pop();
           }
           s.push(i);
        }  
        return P;
    }
};