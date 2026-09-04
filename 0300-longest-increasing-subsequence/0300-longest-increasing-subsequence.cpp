class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> after(n+1,0);
        vector<int> cur(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int previndex=n-1;previndex>=-1;previndex--){
                int nottake=after[previndex+1];
                int take=INT_MIN;
                if(previndex==-1||nums[index]>nums[previndex]){
                    take=1+after[index+1];
                }
                 cur[previndex+1]=max(take,nottake);
            }
            after=cur;
        }
        return after[0];
    }
};