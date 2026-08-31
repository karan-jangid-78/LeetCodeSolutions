class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                 if(buy==1){
        profit=max(-prices[index]+dp[index+1][0],//take
        dp[index+1][1]);//not take
    }
    else{
        profit=max(prices[index]+dp[index+1][1],//take
        dp[index+1][0]);//nottake
    }
     dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};