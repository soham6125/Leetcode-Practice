class MinStack {
public:
    stack<int> stk;
    map<int,int> m;
    MinStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        stk.push(val);
    }
    
    void pop() {
        int val = stk.top();
        stk.pop();
        m[val]--;
        if(m[val] == 0) m.erase(val);
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */