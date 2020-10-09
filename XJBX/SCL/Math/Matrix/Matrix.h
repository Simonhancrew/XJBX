//矩阵类的变换
//+ - *
#include <string.h>
const int MAXN = 1010;
const int MAXM = 1010;
struct Matrix
{
    int m,n;
    int a[MAXN][MAXM];
    //清空数组
    void clear(){
        n = m = 0;
        memset(a,0,sizeof(a));
    }

    Matrix operator + (const Matrix &b) const{
        Matrix tmp;
        tmp.n = n,tmp.m = m;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                tmp.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return tmp;
    }

    Matrix operator- (const Matrix &b) const{
        Matrix tmp;
        tmp.n = n,tmp.m = m;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                tmp.a[i][j] = a[i][j] - b.a[i][j];
            }
        }
        return tmp;
    }
    //矩阵乘法
    Matrix operator* (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        //n*m*bn*bm = n * bm
        tmp.n = n,tmp.m = b.m;
        //首先确定行
        for(int i = 0;i<n;i++){
            //然后确定列
            for(int j = 0;j<b.m;j++){
                //拿出行列相乘求和
                for(int k =0;k<m;k++){
                    //列变行不变，行变列不变
                    tmp.a[i][j] += a[i][k]*b.a[k][j];
                }
            }
        }
        return tmp;
    }
};
