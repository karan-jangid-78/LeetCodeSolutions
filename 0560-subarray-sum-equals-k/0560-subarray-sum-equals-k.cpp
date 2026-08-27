class Solution {
public:
int solve(int index,int k,vector<int>& nums){
    if(index==0) return (nums[0]==k);
    int sum=0;
    int count=0;
    for(int i=index;i>=0;i--){
     sum+=nums[i];
    if(sum==k) count++;
    }
     count+=solve(index-1,k,nums);
     return count;
}
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        return solve(n-1,k,nums);
    }
};