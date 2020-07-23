/*如果在循环中出现了4，一定进入死循环。只需要在循环中判定是否到过4或者1即可。
*/
class Happynum {
public:
    bool isHappy(int n) {
        while (n != 4 && n != 1) {
            string s = to_string(n);
            int sum = 0;
            for (char item: s) {
                sum += (item - '0') * (item - '0');//
            }
            n = sum;
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }

    }
};
//另一种思路快慢指针破循环，在链表中常见。
class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};
