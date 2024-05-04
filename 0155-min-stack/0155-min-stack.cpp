
class MinStack {
        stack <int> stk;
        stack <int> minSofar;

public:
    MinStack() {
        
    }
    
    void push(int val) {
            stk.push(val);

            if(minSofar.empty())
                minSofar.push(val);
            else if(minSofar.top()>val)
                minSofar.push(val);
            else
                minSofar.push(minSofar.top());
    }
    
    void pop() {
            stk.pop(),minSofar.pop();
    }
    
    int top() {
            return stk.top();
    }
    
    int getMin() {
            return minSofar.top();
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