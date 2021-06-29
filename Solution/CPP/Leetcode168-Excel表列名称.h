#include <string>

using namespace std;

// 非常简单，就是一个26进制的问题，但是他的位映射是[1,26]的，所以要集体减一，每次初始的时候去做就可以了
 
class Solution {
public:
    string convertToTitle(int col) {
        string res;
        while(col){
            col--;
            res += (col % 26) + 'A';
            col /= 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};