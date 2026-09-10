class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> after(n+1,0);
        vector<int> cur(n+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&& j==n-1 ) {cur[j]=1; continue;}
                int right=cur[j+1];
                int down=after[j];
                 cur[j]=right+down;
            }
            after=cur;
        }
        return after[0];
    }
};