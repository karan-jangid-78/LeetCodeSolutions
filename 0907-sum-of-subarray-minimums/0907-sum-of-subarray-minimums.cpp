class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long MOD=1e9+7;
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[i]<=arr[st.top()]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> psee(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        long long total=0;
        for(int i=0;i<n;i++){
        long long left=i-psee[i];
        long long right=nse[i]-i;
        total=(total+(right*left*arr[i])%MOD)%MOD;
    }
        return (int)total;
    }
};