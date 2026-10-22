class Solution {
public:
int func(int i,int end,vector<int>& nums,vector<int> &dp){
    int n=nums.size();
    if(i>end) return 0;
    if(dp[i]!=-1) return dp[i];
    int nottake=func(i+1,end,nums,dp);
    int take=nums[i]+func(i+2,end,nums,dp);
    return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int first=func(0,n-2,nums,dp1);
        int second=func(1,n-1,nums,dp2);
        return max(first,second);
    }
};