class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,
                     vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                for(int no_of_transactions=1;no_of_transactions<=2;no_of_transactions++){
                    int profit=0;
                    if(buy==1){
                        profit=max(-prices[index]+dp[index+1][0][no_of_transactions],//take
                        dp[index+1][1][no_of_transactions]);//not take
                    }
                    else{
                        profit=max(prices[index]+dp[index+1][1][no_of_transactions-1],//take
                        dp[index+1][0][no_of_transactions]);//nottake
                    }
                     dp[index][buy][no_of_transactions]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};