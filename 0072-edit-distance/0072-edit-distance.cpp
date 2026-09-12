class Solution {
public:
int func(int i,int j,string &word1,string &word2,vector<vector<int>>& dp){
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j]) return dp[i][j]=func(i-1,j-1,word1,word2,dp);
    else{
    int insert=1+func(i,j-1,word1,word2,dp);
    int deletee=1+func(i-1,j,word1,word2,dp);
    int replace=1+func(i-1,j-1,word1,word2,dp);
    return dp[i][j]=min({insert,deletee,replace});
    }
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,word1,word2,dp);
    }
};