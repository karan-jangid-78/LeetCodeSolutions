class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> after(m+1,0), cur(m+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                    if(i==m-1) cur[j]=triangle[i][j];
                    int down=triangle[i][j]+after[j];
                    int rightdown=triangle[i][j]+after[j+1];
                    cur[j]= min(down,rightdown);
            }
            after=cur;
        }
        return after[0];
    }
};