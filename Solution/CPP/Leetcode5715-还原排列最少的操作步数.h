#include <vector>
using namespace std;
class Solution {
public:
    void work(vector<int> &q){
        vector<int> w;
        for(int i = 0;i < q.size();i += 2) w.push_back(q[i]);
        for(int i = 1;i < q.size();i += 2) w.push_back(q[i]);
        q = w;
    }

    bool check(vector<int> &q){
        for(int i = 0;i < q.size();i++){
            if(q[i] != i){
                return false;
            }
        }
        return true;
    }

    int reinitializePermutation(int n) {
        vector<int> q;
        for(int i = 0;i < n;i++){
            q.push_back(i);
        }
        int cnt = 0;
        while(true){
            cnt++;
            work(q);
            if(check(q)) break;
        }
        return cnt;
    }
};