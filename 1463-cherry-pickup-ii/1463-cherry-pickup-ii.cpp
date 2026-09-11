class Solution {
public:
int func(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
    int m=grid.size();
    int n=grid[0].size();
    //out of bound base case
    if(j1>=n || j1<0 || j2>=n || j2<0) return -1e9;
    //destination base case
    if(i==m-1){
        if(j1==j2) return grid[m-1][j1];
        else return grid[m-1][j1]+grid[m-1][j2];
    }
    //9 possible combos
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=-1e9;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            if(j1==j2){
               maxi=max(maxi,grid[i][j1]+func(i+1,j1+dj1,j2+dj2,grid,dp));
            }
            else{
                maxi=max(maxi,grid[i][j1]+grid[i][j2]+func(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
    }
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return func(0,0,n-1,grid,dp);
    }
};