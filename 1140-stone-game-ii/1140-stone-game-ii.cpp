class Solution {
public:
int func(int person,int i,int M,vector<int>& piles,vector<vector<vector<int>>>& dp){
    int n=piles.size();
    if(i>=n) return 0;
    int stones=0;
    int result=(person==1)?-1:1e9;
    if(dp[person][i][M]!=-1) return dp[person][i][M];
    for(int x=1;x<=min(2*M,n-i);x++){
        stones+=piles[i+x-1];
        if(person==1){//alice turn
            result=max(result,stones+func(0,i+x,max(x,M),piles,dp));
        }
        else{
            result=min(result,func(1,i+x,max(x,M),piles,dp));
        }
    }
    return dp[person][i][M]=result;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(2*n+1,-1)));
        return func(1,0,1,piles,dp);
    }
    };