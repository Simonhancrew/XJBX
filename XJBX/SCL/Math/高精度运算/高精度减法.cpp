#include <iostream>
#include <vector>
using namespace std;

//没有考虑负数

bool cmp(vector<int> &A,vector<int> &B){
    //注意这种比较在代码上的小技巧
    //先比较位数是否等
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1;i >= 0;i--){
        //再比较每一位是否等
        if(A[i] != B[i]){
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    //t是借位标记 0 或者 1
    for(int i = 0,t = 0;i < A.size();i++){
        //结果等于 A[i] - B[i] - t (+ 10)
        //去掉借位项
        t = A[i] - t;
        //正常减B
        if(i < B.size()) t -= B[i];
        //不用借位的话，t+10% 10 = t
        //需要借位的话  t是小于0的，一个式子解决所有的情况
        C.push_back((t + 10) % 10);
        //更新借位的信息
        if(t < 0) t = 1;
        else t = 0;
    }
    //假如相减之后有前导的0，逆序的
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
 

int main(){
    string a,b;
    vector<int> A,B;
    cin >> a >> b;
    for(int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1;i >= 0;i--) B.push_back(b[i] - '0'); 
    vector<int> C;
    if(cmp(A,B)){
        C = sub(A,B);
    }else{
        C = sub(B,A);
        printf("-");
    } 
    for(int i = C.size() - 1;i >= 0;i--) printf("%d",C[i]);
    return 0;
}