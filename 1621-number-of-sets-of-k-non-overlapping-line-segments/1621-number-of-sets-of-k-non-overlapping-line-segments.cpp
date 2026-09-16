class Solution {
public:
int mod=1e9+7;
int f1(int i,int k,int n,vector<vector<int>> &sumdp,vector<vector<int>> &dp){
    if(i==n) return 0;
    if(sumdp[i][k]!=-1) return sumdp[i][k];
    int take=func(i,k,n,sumdp,dp)+f1(i+1,k,n,sumdp,dp);
    return sumdp[i][k]=take%mod;
 }
int func(int i,int k,int n,vector<vector<int>> &sumdp,vector<vector<int>> &dp){
        if(k==0) return 1;
        if(i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int nottake=func(i+1,k,n,sumdp,dp);
        int ans=f1(i+1,k-1,n,sumdp,dp);
        // this is the part which is giving tle so convert this for loop to recursive function
        // for(int j=i+1;j<n;j++){
        //     int take=func(j,k-1,n,dp);
        //     ans=(ans+take)%mod;
        // }
        return dp[i][k]=(nottake+ans)%mod;
}
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>> sumdp(n+1,vector<int>(k+1,-1));
        return func(0,k,n,sumdp,dp);
    }
};