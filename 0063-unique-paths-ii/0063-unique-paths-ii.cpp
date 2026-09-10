class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> after(n+1,0);
        vector<int> cur(n+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j==n-1){
                    if(obstacleGrid[i][j]==1) cur[j]=0;
                    else cur[j]=1;
                    continue;
                }
                    long long right=0,down=0;
                    if(obstacleGrid[i][j]==0){
                    right=cur[j+1];
                    down=after[j];
                    }
                    cur[j]=right+down;
            }
            after=cur;
        }
        return (int)after[0];
    }
};