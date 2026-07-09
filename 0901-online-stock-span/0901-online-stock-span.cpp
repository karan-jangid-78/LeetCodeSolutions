class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ans=INT_MIN;
    int index=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        index++;
        while(!st.empty()&&price>=st.top().first){
            st.pop();
        }
        ans=index-(st.empty()?-1:st.top().second);
        st.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */