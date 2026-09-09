class Solution {
public:
int func(int i,vector<int>& arr,int k,vector<int>& dp){
    int n=arr.size();
    if(i==n) return 0;
    int maxi=INT_MIN;
    int maxsum=INT_MIN;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<min(i+k,n);j++){
        int len=j-i+1;
        maxi=max(maxi,arr[j]);
        int sum=(len*maxi)+func(j+1,arr,k,dp);
        maxsum=max(maxsum,sum);
    }
    return dp[i]=maxsum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
       return func(0,arr,k,dp); 
    }
};