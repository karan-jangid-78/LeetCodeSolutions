class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
         int n=grid[0].size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,1e9));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) {dp[i][j]=grid[i][j]; continue;}
                long long right=grid[i][j]+dp[i][j+1];
                long long down=grid[i][j]+dp[i+1][j];
                 dp[i][j]=min(right,down);
            }
        }
        return (int)dp[0][0];
    }
};