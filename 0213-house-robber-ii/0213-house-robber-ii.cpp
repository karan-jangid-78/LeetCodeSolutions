class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1,0);
        vector<int> dp2(n+2,0);
        for(int index=n-2;index>=0;index--){
            int nottake=0+dp1[index+1];
            int take=nums[index]+dp1[index+2];
            dp1[index]=max(nottake,take);
        }
        int first=dp1[0];
        for(int index=n-1;index>=1;index--){
            int nottake=0+dp2[index+1];
            int take=nums[index]+dp2[index+2];
            dp2[index]=max(nottake,take);
        }
        int second=dp2[1];
        return max(first,second);
    }
};