class Solution {
public:
int func(int i,int tranNo,vector<int> &prices,vector<vector<int>> &dp){
    int n=prices.size();
    if(tranNo==4) return 0;
    if(i==n) return 0;
    if(dp[i][tranNo]!=-1) return dp[i][tranNo];
    if(tranNo%2==0){
        return dp[i][tranNo]=max(-prices[i]+func(i+1,tranNo+1,prices,dp),0+func(i+1,tranNo,prices,dp));
    }
    else{
        return dp[i][tranNo]=max(+prices[i]+func(i+1,tranNo+1,prices,dp),0+func(i+1,tranNo,prices,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(5,-1));
        return func(0,0,prices,dp);
    }
};