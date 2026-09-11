class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2) dp[m-1][j1][j1]=grid[m-1][j1];
                else dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j1=n-1;j1>=0;j1--){
                for(int j2=n-1;j2>=0;j2--){
                     int maxi=-1e9;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            if(j1==j2){
                           if(i+1<m && j1+dj1<n && j1+dj1>=0 && j2+dj2<n && j2+dj2>=0 ) maxi=max(maxi,grid[i][j1]+dp[i+1][j1+dj1][j2+dj2]);
                            }
                            else{
                             if(i+1<m && j1+dj1<n && j1+dj1>=0 && j2+dj2<n && j2+dj2>=0 )   maxi=max(maxi,grid[i][j1]+grid[i][j2]+dp[i+1][j1+dj1][j2+dj2]);
                            }
                        }
                    }
                     dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};