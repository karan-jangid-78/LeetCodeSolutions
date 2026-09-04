class Solution {
public:
int solve(int index,int previndex,vector<int> &nums,vector<vector<int>>& dp){
    if(index==nums.size()) return 0;
    if(dp[index][previndex+1]!=-1) return dp[index][previndex+1];
    int nottake=solve(index+1,previndex,nums,dp);
    int take=INT_MIN;
    if(previndex==-1||nums[index]>nums[previndex]){
         take=1+solve(index+1,index,nums,dp);
    }
    return dp[index][previndex+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};