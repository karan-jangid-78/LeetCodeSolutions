class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l=0,r=0;
        int n=arr.size();
        vector<int> dp(n,1e9);
        int ans=1e9;
        int sum=0;
        while(r<n){
            sum+=arr[r];
            while(sum>target && l<=r){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                int len=r-l+1;
                if(l>0 && dp[l-1]!=1e9){
                    ans=min(ans,len+dp[l-1]);
                }
                dp[r]=(r>0)?min(dp[r-1],len):len;
            }
            else{
                if(r>0) dp[r]=dp[r-1];
            }
            r++;
        }
        return (ans>=1e9)?-1:ans;
    }
};