#include <iostream>
#include <cstring>
#include <algorithm>

//开始枚举c和d，记录在哈希表中
//然后枚举a和b，看看sum = n - a ** 2  - b ** 2在不在哈希表中

using namespace std;


const int N =  5e6 + 10;
int n;
int C[N],D[N];

int main(){
    cin >> n;
    memset(C,-1,sizeof C);
    for(int c = 0;c * c <= n;c++){
        for(int d = c;d * d  + c * c <= n;d++){
            int s = d * d + c * c;
            if (C[s] == -1){
                C[s] = c,D[s] = d;
            }
        }
    }
    
    for(int a = 0;a * a <= n;a ++){
        for(int b = a;a * a + b * b <= n;b++){
            int s = n - a * a - b * b;
            if(C[s] != -1){
                printf("%d %d %d %d",a,b,C[s],D[s]);
                return 0;
            }
        }
    }
    return 0;
}