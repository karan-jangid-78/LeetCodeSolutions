class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) dp[0][target]=1;
        }
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
        unsigned long long nottake=dp[index-1][target];
        unsigned long long take=0;
        if(coins[index]<=target){
            take=dp[index][target-coins[index]];
        }
        dp[index][target]= take+nottake;
            }
        }
        return (int)dp[n-1][amount];
    }
};