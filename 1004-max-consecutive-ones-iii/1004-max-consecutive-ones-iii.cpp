class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int l=0,r=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
            while(k<=0){
                if(nums[l]==0){k++;}
                l++;
            }
        }
            if(nums[r]==0 && k>0){
                k--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};