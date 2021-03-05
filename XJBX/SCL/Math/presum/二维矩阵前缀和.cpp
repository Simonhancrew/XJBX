#include <iostream>
using namespace std;


const int N = 1010;
int a[N][N],s[N][N];

// int main(){
//     int m,n,q;
//     cin >> m>>n>>q;
//     for(int i = 1;i <= m;i++){
//         for(int j = 1; j <= n;j++){
//             scanf("%d",&a[i][j]);
//         }
//     }
//     for(int i = 1;i <= m;i++){
//         for(int j = 1;j <= n;j++){
//             s[i][j] = s[i][j - 1] + s[i - 1][j] + a[i][j] - s[i - 1][j - 1];
//         }
//     }
//     for(int i = 0;i < q;i++){
//         int x1,y1,x2,y2;
//         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//         printf("%d\n",s[x2][y2] - s[x1 - 1][y2] -s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
//     }
//     return 0;
// }


#include <iostream>
using namespace std;


const int N = 1010;
int a[N][N],s[N][N];

int main(){
    int m,n,q;
    cin >> m>>n>>q;
    for(int i = 1;i <= m;i++){
        for(int j = 1; j <= n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    //求二维前缀和
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            s[i][j] = s[i][j - 1] + s[i - 1][j] + a[i][j] - s[i - 1][j - 1];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2] - s[x1 - 1][y2] -s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}