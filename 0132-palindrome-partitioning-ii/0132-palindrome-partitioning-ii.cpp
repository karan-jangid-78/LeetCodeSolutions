class Solution {
public:
bool ispalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int func(int i,string &s,vector<int>& dp){
    int n=s.size();
    if(i==n) return 0;
    int mincost=INT_MAX;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<=n-1;j++){
        if(ispalindrome(i,j,s)){
            int cost =1+func(j+1,s,dp);
             mincost=min(mincost,cost);
        }
    }
    return dp[i]=mincost;
}
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return func(0,s,dp)-1;
    }
};