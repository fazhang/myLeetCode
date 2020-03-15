https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data.push(x);
        int min = x;
        if(!datamin.empty()){
            min = std::min(min,datamin.top());
        }
        datamin.push(min);
    }

    void pop() {
        data.pop();
        datamin.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return datamin.top();
    }

    stack<int> data;
    stack<int> datamin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
