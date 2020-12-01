class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!data.empty()){
            tmp.push(data.front());
            data.pop();
        }
        while(!tmp.empty()){
            data.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = data.front();
        data.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
private:
    queue<int> data;
};
