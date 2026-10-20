class Solution {
   public:
    bool row(int r, int c, vector<vector<char>>& board, int t) {

        for (int i = 0; i < 9; i++) {
            if (board[r][i] == t+'0' && i != c) return true;
        }

        return false;
    }

    bool col(int r, int c, vector<vector<char>>& board, int t) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == t+'0' && i != r) return true;
        }

        return false;
    }

    bool box(int r, int c, vector<vector<char>>& board, int t) {
        int nr = (r / 3) * 3;
        int nc = (c / 3) * 3;

        for (int i = nr; i < nr + 3; i++) {
            for (int j = nc; j < nc + 3; j++) {
                if (board[i][j] == t+'0' && (i != r || j != c)) return true;
            }
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int t = 1; t <= 9; t++) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                        //    cout<<t<<" "<<board[i][j]<<endl;

                    if (board[i][j] == t+'0') {
                        if (row(i, j, board, t)) return false;
                        if (col(i, j, board, t)) return false;
                        if (box(i, j, board, t)) return false;
                    }
                }
            }
        }
        return true;
    }
};
