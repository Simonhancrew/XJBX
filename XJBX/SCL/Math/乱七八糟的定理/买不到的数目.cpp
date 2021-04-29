#include <iostream>

//结论互质的数，无法凑出的最大的数（n - 1） * (m - 1) - 1
using namespace std;

int n,m;

int main()
{
    cin >> n >> m;
    cout <<  n * m - n - m << endl;
    return 0;
}