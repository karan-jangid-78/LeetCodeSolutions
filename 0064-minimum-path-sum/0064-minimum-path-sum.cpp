class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
         int n=grid[0].size();
        vector<int> after(n+1,1e9), cur(n+1,1e9);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) {cur[j]=grid[i][j]; continue;}
                long long right=grid[i][j]+cur[j+1];
                long long down=grid[i][j]+after[j];
                 cur[j]=min(right,down);
            }
            after=cur;
        }
        return (int)after[0];
    }
};