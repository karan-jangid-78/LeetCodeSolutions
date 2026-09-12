class Solution {
public:
bool func(int i, int j, string& s1,string& s2,vector<vector<int>>& dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        for(int ind=i;ind>=0;ind--){
            if(s1[ind]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j] || s1[i]=='?') return dp[i][j]=func(i-1,j-1,s1,s2,dp);
    if(s1[i]=='*'){//naive approach
        for(int k=0;k<=j+1;k++){
            if(func(i-1,j-k,s1,s2,dp)==true) return dp[i][j]=true;

        }
        return dp[i][j]=false;
    }
    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,p,s,dp);
    }
};