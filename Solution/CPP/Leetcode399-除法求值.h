#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
//其实就是一张图，从一个字符串到另外一个字符串要乘以一个权值
//首先给所有的字符串做一个映射
//之后给每一条表赋权值
//然后去搜索答案
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int str_inx = 0;
        unordered_map<string,int> link;
        int n = equations.size();
        //给所有的字符做一个id
        for(int i = 0;i < n;i++){
            if(link.find(equations[i][0]) == link.end()){
                link[equations[i][0]] = str_inx++;
            }
            if(link.find(equations[i][1]) == link.end()){
                link[equations[i][1]] = str_inx++;
            }
        }
        //每条边的权值,id->{id,权值},一共有str_idx个node
        vector<vector<pair<int,double>>> edge(str_inx);
        for(int i = 0;i < n;i++){
            int from = link[equations[i][0]];
            int to =  link[equations[i][1]];
            edge[from].push_back(make_pair(to,values[i]));
            edge[to].push_back(make_pair(from,1.0/values[i]));
        }
        vector<double> ans;
        for(auto q:queries){
            double res = -1.0;
            if(link.find(q[0]) != link.end() && link.find(q[1]) != link.end()){
                int qa_idx = link[q[0]],qb_idx = link[q[1]];
                if(qa_idx == qb_idx){
                    res = 1.0;
                }else{
                    //一个广度搜索
                    queue<int> que;
                    que.push(qa_idx);
                    vector<double> ratios(str_inx,-1.0);
                    ratios[qa_idx] = 1.0;
                    while(!que.empty() && ratios[qb_idx] < 0){
                        auto tmp = que.front();
                        que.pop();
                        for(auto idx:edge[tmp]){
                            if(ratios[idx.first] < 0){
                                ratios[idx.first] = ratios[tmp] * idx.second;
                                que.push(idx.first);
                            }
                        }
                    }
                    res = ratios[qb_idx];
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};