class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2,0);
       dp[n]=1;
       for(int i=n-1;i>=0;i--){
        int one=dp[i+1];
        int second=dp[i+2];
        dp[i]=one+second;
       }
       return dp[0];
    }
};