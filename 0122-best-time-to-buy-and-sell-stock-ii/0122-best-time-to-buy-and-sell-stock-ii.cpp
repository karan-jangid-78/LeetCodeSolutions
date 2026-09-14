class Solution {
public:
int func(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
    int n=prices.size();
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==1){
        return dp[i][buy]=max(-prices[i]+func(i+1,0,prices,dp),0+func(i+1,1,prices,dp));
    }
    else{
        return dp[i][buy]=max(prices[i]+func(i+1,1,prices,dp),0+func(i+1,0,prices,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};