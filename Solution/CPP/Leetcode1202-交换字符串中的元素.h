#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if (s.length() == 1 || pairs.size() == 0) {
            return s;
        }
        //构建一下并查集
        int n = s.size();
        unionset.resize(n);
        for (int i = 0; i < n; ++i) {
            unionset[i] = i;
        }
        for (auto pr : pairs) {
            union_(pr[0],pr[1]);
        }
        //创建map，容纳同圈字符
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int circle = find(i);
            mp[circle].emplace_back(s[i]);
        }
        //对于一个圈子里的char排序
        //注意更改数组取引用
        for (auto &m : mp) {
            sort(m.second.begin(), m.second.end(), [](int lhs, int rhs) {
                return lhs > rhs;
            });
        }
        //还原字符
        for (int i = 0; i < n; i++) {
            int cur = find(i);
            s[i] = mp[cur].back();
            mp[cur].pop_back();
        }
        return s;
    }
private:
    vector<int> unionset;
    int find(int x) {
        if (x == unionset[x]) {
            return x;
        }
        else {
            unionset[x] = find(unionset[x]);
            return unionset[x];
        }
    }
    void union_(int x, int y) {
        if (find(x) == find(y)) {
            return;
        }
        unionset[find(y)] = find(x);
    }
};