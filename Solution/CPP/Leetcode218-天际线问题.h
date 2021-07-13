#include <vector>
#include <algorithm>
#include <set>

// 扫描线问题，这种问题都有通用的思路：扫描线

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int,int>> pt;
        for(auto &b:buildings){//边界排序的问题，左端点的时候要先加入相同x下最大的。
            pt.push_back({b[0],-b[2]});
            pt.push_back({b[1],b[2]});// 右端点的时候
        }
        sort(pt.begin(),pt.end());
        multiset<int> height;
        height.insert(0);
        for(auto& p:pt){
            int x = p.first,h = abs(p.second); 
            if(p.second < 0){//说明是入点
                if(h > *height.rbegin()){
                    res.push_back({x,h});
                }
                height.insert(h);
            }else{
                //出点，只加左端点
                height.erase(height.find(h));
                if(h > *height.rbegin()){
                    res.push_back({x,*height.rbegin()});
                }
            }
        }
        return res;
    }
};