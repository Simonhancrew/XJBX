# include <iostream>
# include <cmath>
using namespace std;

int dgt(int n) // 计算整数n有多少位
{
    int res = 0;
    while (n) ++ res, n /= 10;
    return res;
}

int cnt(int n, int i) // 计算从1到n的整数中数字i出现多少次 
{
    int res = 0, d = dgt(n);
    for (int j = 1; j <= d; ++ j) // 从右到左第j位上数字i出现多少次
    {
        // l和r是第j位左边和右边的整数 (视频中的abc和efg); dj是第j位的数字
        int p = pow(10, j - 1), l = n / p / 10, r = n % p, dj = n / p % 10;
        // 计算第j位左边的整数小于l (视频中xxx = 000 ~ abc - 1)的情况
        if (i) res += l * p; 
        if (!i && l) res += (l - 1) * p; // 如果i = 0, 左边高位不能全为0(视频中xxx = 001 ~ abc - 1)
        // 计算第j位左边的整数等于l (视频中xxx = abc)的情况
        if ( (dj > i) && (i || l) ) res += p;
        if ( (dj == i) && (i || l) ) res += r + 1;
    }
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b , a)
    {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; ++ i) cout << cnt(b, i) - cnt(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}