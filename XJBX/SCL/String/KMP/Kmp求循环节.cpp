#include <iostream>
#include <cstring>
#include <algorithm>
//kmp的一个应用，求循环缀的最短等价于求最大前缀，模拟的时候把原串放下来对比
using namespace std;

const int N = 1e6 + 10;
int ne[N];
char str[N];

int main()
{
    int T = 1;
    int n;
    while(cin >> n,n){
        cin >> str + 1;
        for(int i = 2,j = 0;i <= n;i++){
            while(j && str[i] != str[j+1]) j= ne[j];
            if(str[i] == str[j + 1]) j++;
            ne[i] = j;
        } 

        printf("Test case #%d\n", T ++ );

        for(int i = 1;i <= n;i++){
            int t = i - ne[i];
            //前面有东西，且能够正好背前面的缀整除的才是循环节
            if (i % t == 0 && i / t >= 2)
                printf("%d %d\n", i, i / t);
        }
        puts("");
    }
    return 0;
}

