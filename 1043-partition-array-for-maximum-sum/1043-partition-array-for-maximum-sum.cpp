class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
                int maxi=INT_MIN;
                int len=0;
                int maxsum=INT_MIN;
                for(int j=i;j<min(i+k,n);j++){
                    len++;
                    maxi=max(maxi,arr[j]);
                    int sum=(len*maxi)+dp[j+1];
                    maxsum=max(maxsum,sum);
                }
                dp[i]=maxsum;
             }
       return dp[0];
    }
};