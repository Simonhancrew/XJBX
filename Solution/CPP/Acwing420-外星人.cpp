#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;

int n,m;
int num[N];
//从后往前，找到第一个递增序
//然后讲他和后面第一个比他小的数交换
//最后reverse后面的递减序的数
int main(){
    cin >> n >>m;
    for(int i = 0;i <n;i++) cin >> num[i];
    while(m--){
        int k = n-1;
        while(num[k-1] > num[k]) k--;
        //此时k是一个山峰
        int t = k;
        while(t + 1 < n && num[t+1] > num[k-1])t++;
        swap(num[k-1],num[t]);
        reverse(num+k,num+n);
    }
    for(int i = 0;i < n;i++){
        cout << num[i] << ' ';
    }
    cout << endl;
    return 0;
}