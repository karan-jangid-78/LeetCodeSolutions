class Solution {
public:
string ans="";
void func(int i,int j,string&str1,string&str2,vector<vector<int>>& dp){
    if(j==0){
        while(i>0){
        ans.push_back(str1[i-1]);
        i--;
        }
        return;
    }
    if(i==0){
        while(j>0){
        ans.push_back(str2[j-1]);
        j--;
        }
        return;
    }
    if(str1[i-1]==str2[j-1]){
        ans.push_back(str1[i-1]);
        func(i-1,j-1,str1,str2,dp);
    }
    else{
        if(dp[i-1][j]>=dp[i][j-1]){
            ans.push_back(str1[i-1]);
            func(i-1,j,str1,str2,dp);
        }
        else{
            ans.push_back(str2[j-1]);
            func(i,j-1,str1,str2,dp);
        }
    }
}
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        func(n,m,str1,str2,dp);
        string temp=ans;
        reverse(temp.begin(),temp.end());
        return temp;
    }
};