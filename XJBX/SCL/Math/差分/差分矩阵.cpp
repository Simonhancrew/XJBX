#include <iostream>

using namespace std;

const int N = 1010;


int a[N][N],b[N][N];

//类似于一维差分，[x1,y1]往下的全部+c，但我们只要到[x2,y2]是+c的就可以了。
//剩下一个反L型的区域，类似于二维前缀和,需要做一次减法，期间重复减了一个区域，需要加回来
void insert(int x1,int y1,int x2,int y2,int c){
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){
    int m,n,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
        }
    }

    //假设初始a矩阵为空，去插入每个a[i][j]给矩阵b
    //和一维差分里的初始一样
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            insert(i,j,i,j,a[i][j]);
        }
    }

    for(int i = 0;i < q;i++){
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1,y1,x2,y2,c);
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}