class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                    if(i==m-1) dp[i][j]=triangle[i][j];
                    int down=triangle[i][j]+dp[i+1][j];
                    int rightdown=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]= min(down,rightdown);
            }
        }
        return dp[0][0];
    }
};