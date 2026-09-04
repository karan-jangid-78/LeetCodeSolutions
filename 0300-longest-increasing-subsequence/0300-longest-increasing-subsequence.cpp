class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int previndex=0;previndex<i;previndex++){
                if(nums[i]>nums[previndex]){
                    dp[i]=max(1+dp[previndex],dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};