#include <stack>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N--);
        int idx = 0;
        while (N) {
            if (idx % 4 == 0)  stk.top() *= N;
            else if (idx % 4 == 1)  stk.top() /= N;
            else if (idx % 4 == 2)  stk.push(N);
            else stk.push(-N);
            idx++,N--;
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

//找规律
class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N == 4) return 7;

        if (N % 4 == 0) return N + 1;
        if (N % 4 == 1) return N + 2;
        if (N % 4 == 2) return N + 2;
        return N - 1;
    }
};
