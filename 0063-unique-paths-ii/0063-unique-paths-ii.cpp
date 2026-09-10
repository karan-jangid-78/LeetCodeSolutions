class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j==n-1){
                    if(obstacleGrid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]=1;
                    continue;
                }
                    long long right=0,down=0;
                    if(obstacleGrid[i][j]==0){
                    right=dp[i][j+1];
                    down=dp[i+1][j];
                    }
                     dp[i][j]=right+down;
            }
        }
        return (int)dp[0][0];
    }
};