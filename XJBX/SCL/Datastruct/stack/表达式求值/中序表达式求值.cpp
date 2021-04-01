#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

//表达式树，中序遍历，要注意顺序（后缀和前缀就不存在这个问题）
//遇到中间节点的时候要算一下右子树的值然后才能往上走
//算结果的时候是从下往上的，什么时候才往上，约定一下节点的运算优先级是大于等于当前需要push入的运算符的

using namespace std;

stack<int> nums;
stack<char> op;


void eval(){
    int b = nums.top();nums.pop();
    int a = nums.top();nums.pop();
    auto c = op.top();op.pop();
    int x = 0;
    if(c == '+') x = a + b;
    else if(c == '-') x = a - b;
    else if(c == '*') x = a * b;
    else x = a / b;
    nums.push(x);
}

int main(){
    string s;
    cin >> s;
    //运算符优先级
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for(int i = 0;i < s.size();i++){
        if(isdigit(s[i])){
            int x = 0,j = i;
            while(j < s.size() && isdigit(s[j])){
                x = x * 10 + (s[j++] - '0'); 
            }
            nums.push(x);
            i = j - 1;
        }else if (s[i] == '(') op.push(s[i]);
        else if(s[i] == ')'){
            //遇到括号就把里面的数算完
            while(op.top() != '(') eval();
            op.pop();
        }else{
            //什么时候运算的递归树要往上走?栈内运算符的优先级更大的时候
            //同级运算，从左往右，先算完前面的
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[s[i]]) eval();
            op.push(s[i]);
        }
    }

    while(op.size()) eval();
    cout << nums.top() << endl;
    return 0;
}