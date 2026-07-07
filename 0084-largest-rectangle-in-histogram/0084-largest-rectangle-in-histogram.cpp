class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int x=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                ans=max(ans,x*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int x=heights[st.top()];
            st.pop();
            int pse=st.empty()?-1:st.top();
            int nse=n;
            ans=max(ans,x*(nse-pse-1));
        }
        return ans;
    }
};