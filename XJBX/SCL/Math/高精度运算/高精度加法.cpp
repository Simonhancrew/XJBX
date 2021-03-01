#include <iostream>
#include <vector>
using namespace std;
//首先大整数存储是利用数组存储的
//然后是按照逆序存储的，小的位在数组的头部（为了进位的push方便，不用去整体位移）

/*
高精度加法的模板

// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

*/

//模拟进位加法
vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0;i < A.size() || i < B.size();i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}
 

int main(){

    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0;i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0;i--) B.push_back(b[i] - '0');

    auto C = add(A,B);
    for(int i = C.size() - 1;i >= 0;i--) cout << C[i];
    return 0;
}