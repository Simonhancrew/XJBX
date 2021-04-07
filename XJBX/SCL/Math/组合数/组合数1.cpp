#include <iostream>
#include <algorithm>

//数据范围的问题，一次算出所有的然后去查找，类似于dp
//此处适用a,b比较小的时候

using namespace std;

const int N = 2010,mod = 1e9+7;

int c[N][N];

// C(a,b) = C(a-1,b) + C(a-1,b-1),组合公式
void init(){
    for(int i = 0;i < N;i++){
        for(int j = 0;j <= i;j++){
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}



int main(){
    init();
    int n; 
    cin >> n;
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d",c[a][b]);
    }
    return 0;
}