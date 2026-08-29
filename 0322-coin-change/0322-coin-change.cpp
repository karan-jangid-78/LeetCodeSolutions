class Solution {
public:
int solve(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
    if(index==0){
        if(target%coins[index]==0) return target/coins[index];
        else return 1e9;
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int nottake=solve(index-1,target,coins,dp);
    int take=1e9;
    if(coins[index]<=target){
        take=1+solve(index,target-coins[index],coins,dp);
    }
    return dp[index][target]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};