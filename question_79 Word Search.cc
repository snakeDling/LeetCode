class Solution {
public:
    struct Pos{
        int x;
        int y;
        Pos(int _x, int _y):x(_x),y(_y){}
        Pos():x(-1),y(-1){}
    };
    int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool find_word(vector<vector<char> > &board, const Pos& pre, const char* word){
        if(*word == '\0')
            return true;
        int xMax = board.size(),yMax = board[0].size();
        for(int i=0; i<4; ++i){
            Pos tmp(pre.x+offset[i][0], pre.y+offset[i][1]);
            if(tmp.x < 0 || tmp.x >= xMax
             || tmp.y < 0 || tmp.y >= yMax
             || board[tmp.x][tmp.y] != *word)
                continue;
            char c_tmp = board[tmp.x][tmp.y];
            board[tmp.x][tmp.y] = '\0';
            bool ret = find_word(board, tmp, word+1);
            board[tmp.x][tmp.y] = c_tmp;
            if(ret)
                return true;
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty() || board[0].empty())
            if(word.empty())
                return true;
            else
                return false;
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    char c_tmp = board[i][j];
                    board[i][j] = '\0';
                    bool ret = find_word(board, Pos(i,j), word.c_str()+1);
                    board[i][j] = c_tmp;
                    if(ret)
                        return true;
                }   
            }
        }
        return false;   
    }
}; 