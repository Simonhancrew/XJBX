#include <string>
#include <stack>
using namespace std;
//树是一层一层的，用栈去模拟每一层的逻辑
//除了根节点，每一层的节点可以下面安置两个节点
//就可以在栈中放入当前节点的空间信息
//来了一个空节点的时候，给栈顶的安置点 -1
//来了有值的节点，-1之后还要给顶部加一个有2个安置信息的节点
//首先根节点就只有一个位置，任意节点，当他的安置信息为0的时候就给pop

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        stack<int> stk;
        stk.push(1);
        int i = 0;
        while(i < n){
            if(stk.empty()){
                return false;
            }

            if(preorder[i] == ','){
                ++i;
            }
            else if (preorder[i] == '#'){
                stk.top() -= 1;
                if(stk.top() == 0){
                    stk.pop();
                }
                i++;
            }else{
                while(i < n && preorder[i] != ','){
                    i++;
                }
                stk.top() -= 1;
                if(stk.top() == 0){
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    }
};