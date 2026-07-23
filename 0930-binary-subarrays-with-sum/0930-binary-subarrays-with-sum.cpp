class Solution {
public:
int solve(vector<int>& nums,int goal){
     if(goal<0) return 0;
    int l=0,r=0,count=0;
    long long sum=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            if(sum<=goal){
                count+=r-l+1;
            }
            r++;
        }
        return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
        return solve(nums,goal)-solve(nums,goal-1);
    }
};