class Solution {
public:
int func(int index,int tranNo,vector<int>& prices,vector<vector<int>> &dp){
    if(tranNo>=4||index==prices.size()) return 0;
    int profit=0;
    if(dp[index][tranNo]!=-1) return dp[index][tranNo];
    if(tranNo%2==0){
        profit=max(-prices[index]+func(index+1,tranNo+1,prices,dp),//take
        func(index+1,tranNo,prices,dp));
        }//not take
    else{
        profit=max(prices[index]+func(index+1,tranNo+1,prices,dp),//take
        func(index+1,tranNo,prices,dp));//nottake
    }
    return dp[index][tranNo]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return func(0,0,prices,dp);
    }
};