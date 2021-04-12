#include <iostream>
#include <cstring>
#include <algorithm>
//贪心，后来的数比最后一位大，删除最后一位
using namespace std;

int main(){
    string num;
    cin >> num;
    int k;
    cin >> k;
    string res = "0";
    for(auto &c:num){
        while(k && c < res.back()){
            k--;
            res.pop_back();
        }
        res += c;
    }    
    while(k--) res.pop_back();
    k = 0;
    while(k < res.size() - 1 && res[k] == '0') k++;
    cout << res.substr(k) << endl;
    return 0;
}