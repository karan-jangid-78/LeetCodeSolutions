class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int> prev(n+1,0), cur(n+1,0);
        for(int i=0;i<=m;i++) cur[0]=i;
        for(int j=1;j<=n;j++) prev[j]=j;
        for(int i=1;i<=m;i++){
            cur[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])  cur[j]=prev[j-1];
                else{
                int insert=1+cur[j-1];
                int deletee=1+prev[j];
                int replace=1+prev[j-1];
                 cur[j]=min({insert,deletee,replace});
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};