class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(4+1,0));
        for(int index=n-1;index>=0;index--){
            for(int tranNo=3;tranNo>=0;tranNo--){
                int profit=0;
                if(tranNo%2==0){
                    profit=max(-prices[index]+dp[index+1][tranNo+1],//take
                    dp[index+1][tranNo]);
                    }//not take
                else{
                    profit=max(prices[index]+dp[index+1][tranNo+1],//take
                    dp[index+1][tranNo]);//nottake
                }
                 dp[index][tranNo]=profit;
            }
        }
        return dp[0][0];
    }
};