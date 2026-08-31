class Solution {
public:
int func(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
    if(index==prices.size()) return 0;
    int profit=0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy==1){
        profit=max(-prices[index]+func(index+1,0,prices,dp),//take
        func(index+1,1,prices,dp));//not take
    }
    else{
        profit=max(prices[index]+func(index+1,1,prices,dp),//take
        func(index+1,0,prices,dp));//nottake
    }
    return dp[index][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};