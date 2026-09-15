class Solution {
public:
int func(int index,int previndex,vector<int> &nums,vector<vector<int>> &dp){
    int n=nums.size();
    if(index==n) return 0;
    if(dp[index][previndex+1]!=-1) return dp[index][previndex+1];
    int nottake=0+func(index+1,previndex,nums,dp);
    int take=-1e9;
    if(previndex==-1 || nums[index]>nums[previndex]){
        take=1+func(index+1,index,nums,dp);
    }
    return dp[index][previndex+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,dp);
    }
};