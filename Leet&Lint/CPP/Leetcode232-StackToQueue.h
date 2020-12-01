class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while(!data.empty()){
            tmp.push(data.top());
            data.pop();
        }
        tmp.push(x);
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = data.top();
        data.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return data.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
private:
    stack<int> data;
};
