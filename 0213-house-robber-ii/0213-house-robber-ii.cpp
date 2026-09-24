class Solution {
public:
int func(int index,int end,vector<int> &nums,vector<int> &dp){
    if(index>end) return 0;
    if(dp[index]!=-1) return dp[index];
    int nottake=0+func(index+1,end,nums,dp);
    int take=nums[index]+func(index+2,end,nums,dp);
    return dp[index]=max(nottake,take);
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