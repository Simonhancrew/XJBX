//不同与01背包，完全背包可以重复放入
//所以就不用考虑遍历逆序的问题了
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int m,n;
    while(cin >> n >> m){
        vector<int> w(m);
        vector<int> v(n);
        vector<int> dp(m+1,0);
        for (int i = 0;i < n;i++) cin >> w[i]>>v[i];
        for (int i = 0;i < n;i++) {
            //遍历物品
            for(int j = w[i];j <= m;j++){
                //遍历背包重量，至少要大于当前的物品
                dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
        return 0;
    }
    
}