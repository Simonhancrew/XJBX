#include <vector>
using namespace std;
//贪心，首先20收了之后不能再找出去
//记录5和10的数量
//手下20时，优先找10 + 5的组合
//收下5就不用找，收下10找5
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        if(n == 0){
            return true;
        }
        int five = 0,ten = 0;
        for(auto bill:bills){
            if(bill == 5){
                five++;
            }else if(bill == 10){
                if(five < 1){
                    return false;
                }else{
                    five--;
                    ten++;
                }
            }else{
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};