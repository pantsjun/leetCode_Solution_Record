class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> chessBoard(n, string(n, '.'));
        dfs(n, 0, res, chessBoard);
        return res;
    }
    void dfs(int n, int row, vector<vector<string>> & res,  vector<string>& chessBoard) {
        if (row == n) {
            res.push_back(chessBoard);
            return;
        }
        for(int col = 0; col < n; col++) {
            if (isValid(row, col, n, chessBoard)) {
                chessBoard[row][col] = 'Q';
                dfs(n, row+1, res, chessBoard);
                chessBoard[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string>&chessBoard) {
        
        // 检查固定列每一行上是否有queen
        for(int i = 0 ; i < row; i++) {
            if(chessBoard[i][col] == 'Q'){
                return false;
            }
        }
        // 左上对角检测是否有queen
        for(int i = row -1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        //右上对角检测是否有queen 
        for(int i = row - 1,j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};