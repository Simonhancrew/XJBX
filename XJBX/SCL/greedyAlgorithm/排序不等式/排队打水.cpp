#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

//从小打到排序，然后看每一个位置的贡献

const int N = 1e5 + 10;
int d[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> d[i];
    }
    sort(d,d + n);
    LL res = 0;
    //每一项都会让后面的人等待
    for(int i = 0;i < n;i++) res += d[i] * (n - i - 1);
    cout << res << endl;
    return 0;
}