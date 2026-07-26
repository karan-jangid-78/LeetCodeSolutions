class MinStack {
public:
stack<long long> st;
long long minn=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {st.push(value); minn=value;}
        else{
            if(value>minn){
                st.push(value);
            }
            else {
                st.push((long long)2*value-minn);
                minn=value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            if(st.top()<minn){
                minn=2*minn-st.top();
                }          
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else{
            return st.top()>=minn?(int)st.top():(int)minn;
        }
    }
    
    int getMin() {
        return (int)minn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */