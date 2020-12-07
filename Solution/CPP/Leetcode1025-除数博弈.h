#include <vector>
using namespace std;
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> f(N+2,false);
        f[1] = false;
        f[2] = true;
        for(int i = 3;i<=N;i++){
            for(int j = 1;j<i;j++){
                if(i%j==0&&f[i-j] == false){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[N];
    }
};