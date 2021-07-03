## 从DP的角度看KMP

首先拿出我的观点，求next数组的过程就是一个类似的dp过程。

### 在不加任何思考的情况下做字符串匹配

```
for(int i = 1;i <= n;i++){
    bool flag = true;
    for (int j = 1;j <= m;j++){
        if(s[i + j - 1] != p[j]){
            flag = false;
            break
        } 
    }
}
```

这个复杂度就是两个循环相乘

### 在考虑预处理冗余信息的情况下

pattern串是可能有冗余信息的，这个信息就可以利用，然后做一个加速的处理。

这个处理就是找到一个最长的公共前后缀，当最后一位的不匹配的时候，我可以迁移一下这个前缀到后缀的位置，看看下一个位置能不能匹配，假如还不能匹配，就递归的做这个过程。这不就是终极套娃嘛。

求patter的next数组的过程就是自己的后缀匹配自己前缀的过程，比较粗糙的讲就是自己匹配自己。

这里推荐的写法就是下标从1开始，这样可以少处理一下边界的情况。否则就要让ne[0] = -1

```
#include <iostream>

using namespace std;

const int N = 1e5 + 10,M = 1e6 + 10;

int n,m;
char p[N],s[M];
int ne[N];

int main(){
    cin >> n >> p + 1 >> m >> s + 1;
    for (int i = 2,j = 0;i <= n;i++){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    for(int i = 1,j = 0;i <= m;i++){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n){
            cout << i - j << ' ';
            j = ne[j];
        }
    }
    return 0;
}
```

