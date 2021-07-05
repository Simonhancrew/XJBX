#include <vector>
#include <map>
#include <string>

using namespace std;

// 注意括号处理递归的手法

typedef map<string,int> MPSI;
class Solution {
public:
    map<string,int> dfs(string& str,int& u){
        MPSI res;
        while(u < str.size()){
            // 碰到括号递归的处理
            if(str[u] == '('){
                u++;
                auto t = dfs(str,u);
                u++;
                int cnt = 1,k = u;
                // 括号后还有数字的话
                while(k < str.size() && isdigit(str[k])) k++;
                if(k > u){
                    cnt = stoi(str.substr(u,k - u));
                    u = k;
                }
                // 更新此时括号内的原子
                for(auto& [x,y]:t) res[x] += cnt * y;
            }
            // 括号结束，下层递归的往上走
            else if(str[u] == ')') break;
            else{
                // 普通情况，记录原子
                int k = u + 1;
                while(k < str.size() && str[k] >= 'a' && str[k] <= 'z') k++;
                auto key = str.substr(u,k - u);
                u = k;
                int cnt = 1;
                while(k < str.size() && isdigit(str[k])) k++;
                if(k > u){
                    cnt = stoi(str.substr(u,k - u));
                    u = k;
                }
                res[key] += cnt;
            }
        }
        return res;
    }

    string countOfAtoms(string formula) {
        int k = 0;
        auto t = dfs(formula,k);
        string res;
        for(auto& [x,y]:t){
            res += x;
            if(y > 1) res += to_string(y);
        }
        return res;
    }
};

#include <stack>
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> ans;
        int n = formula.size(),cnt = 1;
        string d,res;
        stack<int> stk;
        string s;
        for(int i = n - 1;i >= 0;i--){
            if(isdigit(formula[i])){
                d = formula[i] + d;
            }else if(formula[i] == ')'){
                int num = d == ""?1:stoi(d);
                d = "";
                cnt *= num;
                stk.push(num);
            }
            else if(formula[i] == '('){
                cnt /= stk.top();
                stk.pop();
            }else{
                s += formula[i];
                if(formula[i] >= 'A' && formula[i] <= 'Z'){
                    reverse(s.begin(),s.end());
                    ans[s] += (d==""?1:stoi(d)) * cnt;
                    d = "";
                    s = "";
                } 
            }
        }
        for(auto& [x,y]:ans){
            res += x;
            if(y > 1) res += to_string(y);
        }
        return res;
    }
};