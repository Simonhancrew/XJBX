#include <string>
#include <stack>
using  namespace std;
//因为只有加减，所以可以开一个栈，只存当前的符号
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> ops;
        int ret = 0;
        ops.push(1);
        int sign = 1;
        int i = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
            }else if (s[i] == '+'){
                sign = ops.top();
                i++;
            }else if(s[i] == '-'){
                sign = -ops.top();
                i++;
            }else if(s[i] == '('){
                ops.push(sign);
                i++;
            }else if(s[i] == ')'){
                ops.pop();
                i++;
            }else{
                long sum = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    sum = sum * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * sum;
            }
        }
        return ret;
    }
};

//双栈，一个存操作，一个存数
class Solution{
public:
    void calcu(stack<int> &nums,stack<char> &ops){
        if(nums.size() < 2 && ops.empty()){
            return;
        }
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();ops.pop();
        nums.push(op == '+'?a + b:a - b);
    }

    //开始是负数的换成 0 - 一个数
    void replace(string &s){
        int pos = s.find("(-");
        while(pos != -1){
            s.replace(pos,string("(-").length(),"(0-");
            pos = s.find("(-");
        }
    }

    int calculate(string s){
        stack<int> nums;
        //防止开头有符号没数字的情况
        nums.push(0);
        stack<char> ops;
        replace(s);
        int n = s.length();
        for(int i = 0;i < n;i++){
            char c = s[i];
            if(c ==' '){
                continue;
            }
            else if (c == '('){
                ops.push(c);
            }else if (c == ')'){
                //计算到左括号
                while(!ops.empty()){
                    char op = ops.top();
                    if(op != '('){
                        calcu(nums,ops);
                    }else{
                        ops.pop();
                        break;
                    }
                }
            }else {
                if(isdigit(c)){
                    int cur = 0;
                    int j = i;
                    while(j < n && s[j] >= '0' && s[j] <= '9'){
                        cur = cur * 10 + (s[j ++ ] - '0');
                    }
                    nums.push(cur);
                    i = j - 1;
                }else{
                    //新的符号入栈之前把之前能算的全部算完
                    while(!ops.empty() && ops.top() != '('){
                        calcu(nums,ops);
                    }
                    ops.push(c);
                }
            }
        }
        while(!ops.empty()){
            calcu(nums,ops);
        }
        return nums.top();
    }
};