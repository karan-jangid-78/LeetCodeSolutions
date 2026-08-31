class Solution {
public:
int func(int index,int buy,vector<int>& prices,int no_of_transactions,vector<vector<vector<int>>> &dp){
    if(index==prices.size()) return 0;
    if(no_of_transactions==0) return 0;
    int profit=0;
    if(dp[index][buy][no_of_transactions]!=-1) return dp[index][buy][no_of_transactions];
    if(buy==1){
        profit=max(-prices[index]+func(index+1,0,prices,no_of_transactions,dp),//take
        func(index+1,1,prices,no_of_transactions,dp));//not take
    }
    else{
        profit=max(prices[index]+func(index+1,1,prices,no_of_transactions-1,dp),//take
        func(index+1,0,prices,no_of_transactions,dp));//nottake
    }
    return dp[index][buy][no_of_transactions]=profit;
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,
                     vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,prices,2,dp);
    }
};