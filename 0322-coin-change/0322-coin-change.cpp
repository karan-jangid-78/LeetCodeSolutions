class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));  
              for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake=dp[index-1][target];
                int take=1e9;
                if(coins[index]<=target){
                    take=1+dp[index][target-coins[index]];
                }
                dp[index][target]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        else return dp[n-1][amount];
    }
};