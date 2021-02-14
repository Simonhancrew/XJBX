#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> parent;
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int index = n / 2;
        parent.resize(index, 0);
        for (int i = 0; i < index; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int lhs = row[i] / 2;
            int rhs = row[i + 1] / 2;
            _union(lhs, rhs);
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < index; i++) {
            mp[find(i)]++;
        }
        int ret = 0;
        for (auto& pr : mp) {
            ret += pr.second - 1;
        }
        return ret;
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void _union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        parent[fy] = fx;
    }
};