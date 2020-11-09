#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        vector<pair<int,int>> dis;
        int pt = 0;
        for(const auto& point:points){
            int distance = pow(point[0],2) + pow(point[1],2);
            dis.push_back({distance,pt});
            ++pt;
        }
        sort(dis.begin(),dis.end(),[](pair<int,int> lhs,pair<int,int> rhs){
            if(lhs.first < rhs.first){
                return true;
            }else{
                return false;
            }
        });
        int index = 0;
        while(K){
            res.push_back(points[dis[index].second]);
            K--;
            index++;
        }
        return res;
    }
};

//优先级队列
#include<queue>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int n = points.size();
        for (int i = K; i < n; ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first) {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};