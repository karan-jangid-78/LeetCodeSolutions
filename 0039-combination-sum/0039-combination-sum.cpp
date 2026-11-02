class Solution {
public:
void func(int i, vector<int>& candidates, int target,vector<vector<int>> &res,vector<int> &ans){
    if(i==candidates.size()){
        if(target==0){
            res.push_back(ans);
            return;
        }
        return;
    }
    if(candidates[i]<=target){
        ans.push_back(candidates[i]);
        func(i,candidates,target-candidates[i],res,ans);
        ans.pop_back();
    }
    func(i+1,candidates,target,res,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        func(0,candidates,target,res,ans);
        return res;
    }
};