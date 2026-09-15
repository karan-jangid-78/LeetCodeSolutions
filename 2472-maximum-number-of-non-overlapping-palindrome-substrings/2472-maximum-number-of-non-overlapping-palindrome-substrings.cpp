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
int func(int i,int k,string &s,vector<int> &dp){
    int n=s.size();
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int nottake=func(i+1,k,s,dp);
    int take1=-1e9,take2=-1e9;
     if(i+k<=n && ispalindrome(i,i+k-1,s))  take1=1+func(i+k,k,s,dp);
    if(i+k+1<=n && ispalindrome(i,i+k,s))  take2=1+func(i+k+1,k,s,dp);
    return dp[i]=max({nottake,take1,take2});
}
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n,-1);
        return func(0,k,s,dp);
    }
};