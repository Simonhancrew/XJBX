//欧几里得算法，最大公约数,辗转相除

#include <iostream>


using namespace std;


int gcd(int a,int b){
    return b?gcd(b,a % b):a;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
