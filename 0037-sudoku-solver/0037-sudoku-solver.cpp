class Solution {
public:
bool solve(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(board,i,j,c)){
                        board[i][j]=c;
                       if(solve(board)==true) 
                       return true;//from this when the board is completely filled a chain of returning true forms
                       else  board[i][j]='.';
                    }
                }
                return false;//this false means that none of the char(0-9) can be filled it means the upper recursive call is wrong and should explore another value 
                // the current choices made by previous recursive calls are invalid.
                // Return false so the previous call backtracks and tries another digit.
            }
        }
    }
    return true;//this true means that all the board is filled and eventually it returns a true means that suduko is solved 
}
bool isvalid(vector<vector<char>>& board,int row,int col,int c){
    for(int i=0;i<9;i++){
        if(board[row][i]==c) return false;
        if(board[i][col]==c) return false;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c) return false;
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};