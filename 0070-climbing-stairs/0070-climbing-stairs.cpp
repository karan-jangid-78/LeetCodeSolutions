class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2,0);
        dp[n]=1;
        for(int index=n-1;index>=0;index--){
            int take1=dp[index+1];
            int take2=dp[index+2];
            dp[index]=take1+take2;
        }
        return dp[0];
    }
};