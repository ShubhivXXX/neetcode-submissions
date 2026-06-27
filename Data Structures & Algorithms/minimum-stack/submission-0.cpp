class MinStack {
    private: stack<int> s;
        stack<int> min;
public:
    MinStack() {

    }
    
    void push(int val) {
            s.push(val);
            if(min.empty() || min.top()>= val){
                min.push(val);
            }
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if(!min.empty() && top == min.top()){
            min.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }return -1;
    }
    
    int getMin() {
        if(!min.empty()){
            return min.top();
        }
        return -1;
    }
};
