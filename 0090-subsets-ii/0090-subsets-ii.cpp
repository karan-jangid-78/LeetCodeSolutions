class Solution {
public:
vector<vector<int>> result;
vector<int> ans;
void solve(vector<int>& nums,int index){
    result.push_back(ans);//because whenever a function is called i'm sure that it comes after skipping   //the duplicats and pushed into ans
    for(int i=index;i<nums.size();i++){
        if(i>index&&nums[i]==nums[i-1]) continue;//index ==from where function starts to making choice so //that when i backtrack then i can have this information that i can start from here to make choice
        ans.push_back(nums[i]);
        solve(nums,i+1);
        //backtrack
        ans.pop_back();
        
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return result;
    }
};