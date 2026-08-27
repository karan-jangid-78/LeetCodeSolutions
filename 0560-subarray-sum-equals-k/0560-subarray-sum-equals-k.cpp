class Solution {
public:
int solve(int index,int k,vector<int>& nums,vector<int>& dp){
    if(index==0) return (nums[0]==k);
    int sum=0;
    int count=0;
    for(int i=index;i>=0;i--){
     sum+=nums[i];
    if(sum==k) count++;
    }
    if(dp[index]!=-1) return dp[index];
     count+=solve(index-1,k,nums,dp);
     return dp[index]=count;
}
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,k,nums,dp);
    }
};