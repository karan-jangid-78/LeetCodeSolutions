class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int index=n-1;index>=0;index--){
            int nottake=0+dp[index+1];
            int take=nums[index]+dp[index+2];
            dp[index]=max(nottake,take);
        }
        return dp[0];
    }
};