#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


int main(){
    int l;
    cin >> l;
    vector<string> tokens;
    stack<int> nums;
    while(l--){
        string e;
        cin >> e;
        tokens.push_back(e);
    }
    for(auto &t:tokens){
        if(t == "+" || t == "-" || t == "*" || t =="/"){
            int b = nums.top();nums.pop();
            int a = nums.top();nums.pop();
            if(t == "+") nums.push(a + b);
            else if(t == "-") nums.push(a - b);
            else if(t == "*") nums.push(a * b);
            else nums.push(a / b);
        }else{
            nums.push(stoi(t));
        }
    }
    cout << nums.top();
    return 0;
}