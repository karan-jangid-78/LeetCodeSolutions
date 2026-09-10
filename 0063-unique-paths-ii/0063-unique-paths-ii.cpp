class Solution {
public:
int func(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(i==m-1 && j==n-1){
        if(obstacleGrid[i][j]==1) return 0;
        else return 1;
    }
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=0,down=0;
    if(obstacleGrid[i][j]==0){
     right=func(i,j+1,obstacleGrid,dp);
     down=func(i+1,j,obstacleGrid,dp);
    }
    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,obstacleGrid,dp);
    }
};