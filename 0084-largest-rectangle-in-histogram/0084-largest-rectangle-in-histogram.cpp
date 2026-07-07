class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> nse(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};