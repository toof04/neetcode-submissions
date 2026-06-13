class MinStack {
private:
    stack<int>minst;
    stack<int>s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minst.empty() or val<=minst.top()){
        minst.push(val);
        } else minst.push(minst.top()); 
    }
    
    void pop() {
        minst.pop();
        s.pop();


    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(minst.empty())return -1;
        return minst.top();
    }
};
