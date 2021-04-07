#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110; 

int n;
int a[N][N];

int xor_gauss(){
    int c,r;
    for(int c = 0,r = 0;c < n;c++){
        int t = r;
        for(int i = r;i < n;i++){
            if(a[i][c] == 1){
                t = i;
                break;
            }
        }
        
        if(!a[t][c]) continue;
        
        for(int i = c;i <= n;i++) swap(a[r][i],a[t][i]);
        for(int i = r + 1;i < n;i++){
            if(a[i][c]){
                for(int j = c;j <= n;j++){
                    a[i][j] ^= a[r][j];
                }
            }
        }
        r++;
    }
    if(r < n){
        for(int i = r;i < n;i++){
            if(a[i][n]){
                return 2;
            }
        }
        return 1;
    }
    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            a[i][n] ^= a[i][j] & a[j][n];
        }
    }
    
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            cin >> a[i][j];
        }
    }
    
    int t = xor_gauss();
    
    if(t == 0){
        for (int i = 0;i < n;i++) printf("%d\n",a[i][n]);
    }else if(t == 1) puts("Multiple sets of solutions");
    else puts("No solution");
    
    return 0;
}