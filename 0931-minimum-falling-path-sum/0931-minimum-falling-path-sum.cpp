class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> after(n+1,0), cur(n+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1){cur[j]=matrix[i][j];continue;}
                int down=matrix[i][j]+after[j];
                int downleft=1e9;
                if(j-1>=0) downleft=matrix[i][j]+after[j-1];
                int downright=1e9;
                if(j+1<n) downright=matrix[i][j]+after[j+1];
                cur[j]=min({down,downleft,downright});
            }
            after=cur;
        }
        int ans=1e9;
        for(int k=0;k<n;k++){
            ans=min(ans,after[k]);
        }
        return ans;
    }
};