class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=nums[st.top()]){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> pgee(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                st.pop();
            }
            pgee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
         while(!st.empty()){
            st.pop();
        }
        vector<int> nse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
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
            while(!st.empty()&&nums[i]<nums[st.top()]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
         long long total1=0;
          long long total2=0;
        for(int i=0;i<n;i++){
            long long l1=i-pgee[i];
            long long r1=nge[i]-i;
            total1+=l1*r1*nums[i];
            long long l2=i-psee[i];
            long long r2=nse[i]-i;
            total2+=l2*r2*nums[i];
        }
        return total1-total2;
    }
};