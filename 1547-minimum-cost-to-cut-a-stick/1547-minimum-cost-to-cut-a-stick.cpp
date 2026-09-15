class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=m-2;i>=1;i--){
            for(int j=1;j<=m-2;j++){
                if(i>j)  continue;
                int mini=1e9;
                for(int k=i;k<=j;k++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,cost);
            }
             dp[i][j]=mini;
            }
        }
        return dp[1][m-2];
    }
};