#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> q(n,vector<int> (2,0));
    for(int i = 0;i < n;i++){
        cin >> q[i][0] >> q[i][1];
    }
    sort(q.begin(),q.end(),[](vector<int> &lhs,vector<int> &rhs){ return lhs[0] < rhs[0];});
    int res = 1;
    int l = q[0][0],r = q[0][1];
    for(int i = 1;i < n;i++){
        if(r < q[i][0]){
            l = q[i][0];
            r = q[i][1];
            res++;
        }else{
            r = max(r,q[i][1]);
        }
    }
    cout << res;
    return 0;
}


/*
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
*/