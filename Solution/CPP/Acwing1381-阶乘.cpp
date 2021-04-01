#include <iostream>
#include <algorithm>

// 求最右边的第一个非零数等价于分解n的阶乘中有多少个10，等价于分解有多少个2 * 5，我们拿到2和5的幂次。
// 对于其幂次的最小值k,我们不将这个2 * 5乘入res，然后找到把需要乘的2 或 5 乘进去取mod。
//剩下一部分的数，我们不关心，直接边算边乘就行，记得mod 10

using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 1,d2 = 0,d5 = 0;
    for(int i = 1;i <= n;i++){
        int x = i;
        while(x % 2 == 0) x /= 2,d2++;
        while(x % 5 == 0) x /= 5,d5++;
        res = x * res % 10; 
    }
    int k = min(d2,d5);
    for(int i = 0;i < d2 - k;i++) res = res * 2 % 10;
    for(int i = 0;i < d5 - k;i++) res = res * 5 % 10;
    cout << res;
    return 0;
}