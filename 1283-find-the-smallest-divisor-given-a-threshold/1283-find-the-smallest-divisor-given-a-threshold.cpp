class Solution {
public:
bool solve(vector<int>& nums, int threshold,int k){
    int count=0;
    for(int i=0;i<nums.size();i++){
        count+=ceil((double)nums[i]/(double)k);
    }
    return count<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
      
        int max=*max_element(nums.begin(),nums.end());
        int low=1,high=max;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,threshold,mid)==true){
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return low;
    }
};