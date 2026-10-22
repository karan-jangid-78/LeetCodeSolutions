class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[0];
    }
};