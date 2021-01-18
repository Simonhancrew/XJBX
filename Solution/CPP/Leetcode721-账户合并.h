#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
//确定唯一不变量，邮件地址
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //依靠唯一id确定email的归属
        unordered_map<string,int> email2index;
        unordered_map<string,string> email2name;
        for(auto &account:accounts){
            string name = account[0];
            int n = account.size();
            for(int i = 1;i < n-1;i++){
                if(email2index.count(account[i]) == 0){
                    email2index[account[i]] =  email2index.size();
                    email2name[account[i]] = name;
                }
            }
        }
        //并查集的数量大小就是email的数量
        int n = email2index.size();
        parent.resize(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
        //对每一个account，利用唯一id合并他的email，同一个人email在不同组下
        //会合并成一个集合
        for(auto &account:accounts){
            int first_index = email2index[account[1]];
            for(int i = 2;i < account.size()-2;i++){
                _union(first_index,email2index[account[i]]);
            }
        }
        //此处要用id，避免重名
        unordered_map<int,vector<string>> index2email;
        for(auto link:email2index){
            int index = find(link.second);
            index2email[index].push_back(link.first);
        }
        vector<vector<string>> ans;
        for(auto &link:index2email){
            sort(link.second.begin(),link.second.end());
            string name = email2name[link.second[0]];
            auto cur = link.second;
            cur.insert(cur.begin(),name);
            ans.push_back(cur);
        }
        return ans;
    }
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void _union(int x,int y){
        int fx = find(x),fy = find(y);
        if(fx == fy){
            return;
        }
        parent[fy] = fx;
    }
};