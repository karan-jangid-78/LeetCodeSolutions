class Solution {
public:
bool solve(vector<int>& nums, int k,int capacity){
    int nop=1;
    int carryingthecapacity=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+carryingthecapacity<=capacity){
            carryingthecapacity+=nums[i];
        }
        else{
            carryingthecapacity=nums[i];
            nop++;
        }
    }
    return nop<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
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