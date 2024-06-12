class Solution {
public:

    //Approach 1 : traditional n queen 
    //Approach 2 : optimiszing in isVALID by using unordredset performing operationn in O(1)

    vector<vector<string>> result;

    unordered_set<int> cols;
    unordered_set<int> diagonal;
    unordered_set<int> antiDiagonal;

    bool isValid (vector<string>& board,int row ,int col) {
        int n = board.size();
        //upper row
        for (int i = row -1; i >= 0;i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        //upper right diagonal
        for (int i = row -1, j = col +1; i >= 0 && j < n;i--,j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        //upper left fiagonal
         for (int i = row -1, j = col -1; i >= 0 && j >= 0;i--,j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve (vector<string>& board,int row) {
        int n = board.size();
        
        if (row >= n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n;col++) {
            
            if (isValid(board,row,col) ) {
                board[row][col] = 'Q';
                solve (board,row + 1);
                board[row][col] = '.';
            }
        }
    }
    void solve2 (vector<string>& board,int row) {
        int n = board.size();
        
        if (row >= n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n;col++) {
            
            int diagonalConst = row + col;
            int antiDiagonalConst = row - col;

            if (cols.find(col) !=  cols.end() || diagonal.find(diagonalConst) != diagonal.end() || antiDiagonal.find(antiDiagonalConst) != antiDiagonal.end() ) {
                continue;
            }

            cols.insert(col);
            diagonal.insert(row + col);
            antiDiagonal.insert(row - col);
            board[row][col] = 'Q';

            solve2 (board, row + 1);

            cols.erase(col);
            diagonal.erase(row + col);
            antiDiagonal.erase(row - col);
            board[row][col] = '.';



        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        // vector<string> board(n,string(n,'.'));

        // solve (board,0);

        // return result;


        //approach 2:

        
        vector<string> board(n,string(n,'.'));
        

        solve2 (board,0);

        return result;
    }

};