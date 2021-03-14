#include <iostream>

using namespace std;

//从最朴素的出发，给定n长度string，m长度pattern，如何判断string中pattern出现的位置？
/*
    不难想出一个暴力的解法
    for(int i = 1;i <= n;i++){
        bool flag = true;
        for (int j = 1;j <= m;j++){
            flag = false;
            if(s[i + j - 1] != p[j]){
                break
            } 
        }

    }


（此处假设下表从1开始）

之后我们想如何去优化他，不难想到，这个pattern串最少往后移动多少能继续和string匹配上。（在代码中体现为，i是永远往前移动的，而j是可以反复横跳的）
这就等价于找到一个前缀和后缀相等的最大，这样，前缀的部分能移动到后缀的部分去。
ex：
例如，我们匹配到了i-1，j这一对，i和j+1是不匹配的，我们找到ne[j],把j变为ne[j]，这样等价于让patter串往前移动了，我们继续考察s[i]和p[j+1]是否匹配，不匹配的话是可以递归的处理j的


之后关于next数组的求法，极度类似于前面的匹配(以模式字符串为主字符串，以模式字符串的前缀为目标字符串)
我们不处理长度为1的值，因为next[1]是没有意义的，我们理想下公共前后缀的长度是不能大于等于自身的
从2开始，给（1，i）找一个匹配的前后缀，假设此时完成了一个到i-1的匹配，i和j+1是不匹配的
此时我们找到ne[j],看看ne[j] +1和i位置的字符能否匹配，能的话就更新ne[i] 
*/





const int N = 1e5+10,M = 1e6 + 10;

char s[M],p[N];
//next数组
int ne[N];

int main(){
    int m,n;
    cin >> n >> p+1 >> m >> s + 1;
    //创建next数组的过程
    for(int i = 2, j =0;i <= n;++i){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    
    //kmp匹配的过程
    for(int i = 1,j = 0;i <= m;++i){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == n){
            cout << i - j << ' ';
            j = ne[j];
        }
    }
    return 0;
}


//从0开始的，在做一些题目的时候给的是string，需要原位去判断，不构建char*
#if 0
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, m;
char s[N], p[N];
int ne[N];

int main()
{
    cin >> m >> p >> n >> s;

    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m - 1)
        {
            cout << i - j << ' ';
            j = ne[j];
        }
    }

    return 0;
}
#endif