class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2,0);
        dp[n-1]=cost[n-1];
        for(int i=n-2;i>=0;i--){
            int one=cost[i]+dp[i+1];
            int second=cost[i]+dp[i+2];
            dp[i]=min(one,second);
        }
        return min(dp[0],dp[1]);
    }
};