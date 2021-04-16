#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!que.empty()){
            tmp.push(que.front());
            que.pop();
        }
        while(!tmp.empty()){
            que.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int first = que.front();
        que.pop();
        return first;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};