class Solution {
public:
bool solve(vector<int>& nums, int k,int pages){
    int nos=1;
    int sp=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]+sp<=pages){
            sp+=nums[i];
        }
        else{
            nos++;
            sp=nums[i];
        }
    }
    return nos<=k;
}
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int max=*max_element(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int low=max,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,k,mid)==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};