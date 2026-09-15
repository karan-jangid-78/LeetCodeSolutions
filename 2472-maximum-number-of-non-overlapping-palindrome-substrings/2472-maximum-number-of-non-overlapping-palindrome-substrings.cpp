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

    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n+k,0);
        for(int i=n-1;i>=0;i--){
            int nottake=dp[i+1];
            int take1=-1e9,take2=-1e9;
            if(i+k<=n && ispalindrome(i,i+k-1,s))  take1=1+dp[i+k];
            if(i+k+1<=n && ispalindrome(i,i+k,s))  take2=1+dp[i+k+1];
             dp[i]=max({nottake,take1,take2});
        }
        return dp[0];
    }
};