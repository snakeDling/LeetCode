class Solution {
public:
    int cells[9][9];
    bool rowCheck[9][9];
    bool columnCheck[9][9];
    bool areaCheck[9][9];

    bool _insert(int x, int y, int val){
        if(rowCheck[x][val] || columnCheck[y][val] || areaCheck[x-(x%3)+y/3][val]){
            return false;
        }else{
            rowCheck[x][val] = true;
            columnCheck[y][val] = true;
            areaCheck[x-(x%3)+y/3][val] = true;
            cells[x][y] = val;
            return true;
        }
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(cells, 0, sizeof(int)*9*9);
        memset(rowCheck, 0, sizeof(bool)*9*9);
        memset(columnCheck, 0, sizeof(bool)*9*9);
        memset(areaCheck, 0, sizeof(bool)*9*9);
        for(int x=0; x<9; ++x){
            for(int y=0; y<9; ++y){
                if(board[x][y] == '.')
                    continue;
                if(!_insert(x, y, board[x][y] - '1'))
                    return false;
            }
        }
        return true;
    }
};