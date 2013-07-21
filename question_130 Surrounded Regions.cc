class Solution {
public:
    void solve(vector<vector<char>> &board, int x, int y, int n){
        if(board[x][y] == 'O'){
            board[x][y] = '0';
            if(x<n-1)
                solve(board, x+1, y, n);
            if(x>1)
                solve(board, x-1, y, n);
            if(y<n-1)
                solve(board, x, y+1, n);
            if(y>1)
                solve(board, x, y-1, n);
        }
            
    }

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size()<2)
            return;
        int n=board.size()-1;
        for(int i=0; i<=n; ++i){
            solve(board, 0, i, n);
            solve(board, i, 0, n);
            solve(board, n, i, n);
            solve(board, i, n, n);
        }
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                if(board[i][j] == '0')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
        return;
    }
};