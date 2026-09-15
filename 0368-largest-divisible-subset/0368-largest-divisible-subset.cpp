class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> backtrack(n);
        sort(nums.begin(),nums.end());
        int maxi=0;
        int lastindex=0;
        for(int i=0;i<n;i++){
            backtrack[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    backtrack[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(backtrack[lastindex]!=lastindex){
            lastindex=backtrack[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};