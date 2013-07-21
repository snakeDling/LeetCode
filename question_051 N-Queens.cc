class Solution {
public:
    vector<vector<string> > result;
    vector<bool> hash_row;
    vector<vector<bool>> hasn_diagonal;
    vector<string> board;
    void make_quine(int y, int n){
        if(y == n){
            result.push_back(board);
            return;
        }
        for(int x=0; x<n; ++x){
            if(hash_row[x] && hasn_diagonal[0][x+y] && hasn_diagonal[1][n-x-1+y]) {
                hash_row[x] = false;
                hasn_diagonal[0][x+y] = false;
                hasn_diagonal[1][n-x-1+y] = false;
                board[x][y] = 'Q';
                make_quine(y+1, n);
                hash_row[x] = true;
                hasn_diagonal[0][x+y] = true;
                hasn_diagonal[1][n-x-1+y] = true;
                board[x][y] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        hash_row.clear();
        hasn_diagonal.clear();
        board.clear();
        hash_row.resize(n, true);
        hasn_diagonal.resize(2,vector<bool>(n+n-1, true));
        board.resize(n, string(n, '.'));
        make_quine(0, n);
        return result;
    }
};