class Solution {
public:
int func(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
    int m=grid.size();
    int n=grid[0].size();
    if(i==m-1 && j==n-1) return grid[i][j];
    if(i>=m || j>=n) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    long long right=grid[i][j]+func(i,j+1,grid,dp);
    long long down=grid[i][j]+func(i+1,j,grid,dp);
    return  dp[i][j]=(int)(min(right,down));
}
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
         int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,grid,dp);
    }
};