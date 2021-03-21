#include <iostream>
#include <cstring>
using namespace std;

//一般数据都不会大于10 ** 9所以很多人喜欢用0x3f3f3f3f储存一个不存在，而且又不至于无穷大的情况
//然后我们会取一个2~3倍的经验值作为哈希的base数组
const int N = 2e5 + 3,null = 0x3f3f3f3f;

int h[N];

//开放地址法的核心就是find函数
//没有这个数返回的就是这个数插在哪里，有这个数返回的就是这个数在数组里的下标
int find(int x){
    //处理负数的情况
    int k = (x % N + N) % N;
    //对于一个坑位，如果有人就继续往后走，没人就站下来
    //查找的时候就找这个坑位上的是不是x，不是就继续往后找
    while(h[k] != null && h[k] != x){
        k++;
        //到了最末尾，还有人，就从头开始
        if(k == N) k = 0;
    }
    return k;
} 

int main(){
    int n;
    scanf("%d",&n);
    //对字节操作，所以0x3f就直接全部0x3f3f3f3f
    memset(h,0x3f,sizeof(h));
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        int k = find(x);
        if (op[0] == 'I'){
            h[k] = x;
        }else{
            if(h[k] != null) cout <<"Yes"<<endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}