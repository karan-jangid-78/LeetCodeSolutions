class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> backtrack(n);
        int maxi=0;
        int lastindex=0;
        for(int index=0;index<n;index++){
            backtrack[index]=index;
            for(int previndex=0;previndex<index;previndex++){
                if(nums[index]>nums[previndex] && dp[previndex]+1>dp[index]){
                    dp[index]=1+dp[previndex];
                    backtrack[index]=previndex;
                }
            }
            if(dp[index]>maxi){
                maxi=max(maxi,dp[index]);
                lastindex=index;
            }
        }
        return maxi;
    }
};