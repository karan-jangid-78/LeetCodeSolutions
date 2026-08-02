class Solution {
public:
vector<vector<int>> result;
void solve(vector<int>& nums,vector<int> &ans,int index){
    //ans is passed by reference so there is only one vector throughout the recursion and no copy of ans
    int n=nums.size();
    if(index==n){
        result.push_back(ans);
        return;
    }
    //take the current element
    ans.push_back(nums[index]);
    solve(nums,ans,index+1);
    //backtrack
    ans.pop_back();
    //exploring by removing the current elment
    solve(nums,ans,index+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solve(nums,ans,0);
        return result;
    }
};