class Solution {
public:
int solve(vector<int>& nums, int k){
    int n=nums.size();
    int l=0,r=0,count=0,ans=0;
    while(r<n){
        if(nums[r]%2==1) count++;
        while(count>k){
            if(nums[l]%2==1) count--;
            l++;
        }
        if(count<=k){
            ans+=r-l+1;
        }
        r++;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};