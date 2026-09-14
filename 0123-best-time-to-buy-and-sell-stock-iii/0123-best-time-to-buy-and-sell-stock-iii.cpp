class Solution {
public:
int func(int i,int buy,int tranNo,vector<int> &prices,vector<vector<vector<int>>> &dp){
    int n=prices.size();
    if(tranNo==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][tranNo]!=-1) return dp[i][buy][tranNo];
    if(buy==1){
        return dp[i][buy][tranNo]=max(-prices[i]+func(i+1,0,tranNo,prices,dp),0+func(i+1,1,tranNo,prices,dp));
    }
    else{
        return dp[i][buy][tranNo]=max(+prices[i]+func(i+1,1,tranNo-1,prices,dp),0+func(i+1,0,tranNo,prices,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,prices,dp);
    }
};