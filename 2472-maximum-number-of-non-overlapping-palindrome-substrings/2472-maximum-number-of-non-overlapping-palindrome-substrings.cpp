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
    int maxi=-1e9;
    for(int len=k;i+len<=n;len++){
        if(ispalindrome(i,i+len-1,s)==true){
           int take=1+func(i+len,k,s,dp);
            maxi=max(maxi,take);
        }
    }
    return dp[i]=max(maxi,nottake);
}
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n,-1);
        return func(0,k,s,dp);
    }
};