class Solution {
public:
    int cells[9][9];
    bool rowCheck[9][10];
    bool columnCheck[9][10];
    bool areaCheck[9][10];

    void init(){
        memset(cells, 0, sizeof(int)*9*9);
        memset(rowCheck, 0, sizeof(bool)*9*10);
        memset(columnCheck, 0, sizeof(bool)*9*10);
        memset(areaCheck, 0, sizeof(bool)*9*10); 
    }

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
    
    void _remove(int x, int y, int val){
        rowCheck[x][val] = false;
        columnCheck[y][val] = false;
        areaCheck[x-(x%3)+y/3][val] = false;
        cells[x][y] = 0;
    }
    
    bool _solve(int x, int y){
        if(y == 9)
            return true;
        if(cells[x][y] != 0)
            return _solve((x+1)%9, y+(x>>3));
        for(int i=1; i<=9; ++i){
            if(_insert(x, y, i)){
                if(_solve((x+1)%9, y+(x>>3)))
                    return true;
                else
                    _remove(x, y, i);
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init();
        for(int x=0; x<9; ++x){
            for(int y=0; y<9; ++y){
                if(board[x][y] == '.')
                    continue;
                _insert(x, y, board[x][y]-'0');
            }
        }
        _solve(0, 0);
        for(int x=0; x<9; ++x){
            for(int y=0; y<9; ++y){
                board[x][y] = '0' + cells[x][y];
            }
        }
        
    }
};