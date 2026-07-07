class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(i>=k){
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0){
                    mp.erase(nums[i-k]);
                }
            }
            if(i>=k-1){
                ans.push_back(mp.rbegin()->first);
            }
        }
        return ans;
    }
};