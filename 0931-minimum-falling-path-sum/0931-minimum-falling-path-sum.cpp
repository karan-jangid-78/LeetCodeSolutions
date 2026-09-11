class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1){dp[i][j]=matrix[i][j];continue;}
                int down=matrix[i][j]+dp[i+1][j];
                int downleft=1e9;
                if(j-1>=0) downleft=matrix[i][j]+dp[i+1][j-1];
                int downright=1e9;
                if(j+1<n) downright=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min({down,downleft,downright});
            }
        }
        int ans=1e9;
        for(int k=0;k<n;k++){
            ans=min(ans,dp[0][k]);
        }
        return ans;
    }
};