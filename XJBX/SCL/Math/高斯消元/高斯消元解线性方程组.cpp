#include <iostream>
#include <cmath>
#include <algorithm>

//线性代数，变化为上三角形式

using namespace std;

const int N  = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss(){
    //当前启示行列
    int c,r;
    //从列枚举
    for(c = 0,r = 0;c < n;c++){
        //找到这一列中绝对值最大的行
        int t = r;
        for(int i = r + 1;i < n;i++){
            if(fabs(a[i][c]) > fabs(a[t][c])){
                t = i;
            }
        }
        //当前位置的值为0，没有意义继续。
        if(fabs(a[t][c]) < eps) continue;
        //把绝对值最大的和当前顶行交换
        //swap(a[t],a[r]);
        for(int i = c;i <= n;i++) swap(a[t][i],a[r][i]);
        //归一        
        for(int i = n;i >= c;i--) a[r][i] /= a[r][c];
        //变成阶梯型，消元，消去下方列不是0的
        for(int i = r + 1;i < n;i++){
            if(fabs(a[i][c]) > eps){
                for(int j = n;j >= c;j--){
                    a[i][j] -= a[r][j] * a[i][c];  
                }
            }
        }
        r++;
    }
    //已经是阶梯的了，剩下的左边一定是0，看看是无解还是无数解
    if (r < n){
        for(int i = r;i < n;i++){
            //0 = !0
            if(fabs(a[i][n]) > eps){
                return 2;
            }
            return 1;
        }
    }

    //把方程的值值回代回去，变成对角线形
    //从下往上消去末尾多余的系数
    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 0;
}


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n + 1;j++){
            cin >> a[i][j];
        }
    }
    int t = gauss();
    if(t == 0){
        for(int i = 0;i < n;i++){
            printf("%.2lf\n",a[i][n]);
        }
    }else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");
    return 0;
}