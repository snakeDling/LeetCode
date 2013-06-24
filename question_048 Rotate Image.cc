class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size()-1;
        for(int x=n/2; x>=0; --x){
            for(int y=(n-1)/2; y>=0; --y){
                int cur_x = x,cur_y=y;
                for(int i=0; i<3; ++i){
                    int tmp = n-cur_x;
                    cur_x = cur_y;
                    cur_y = tmp;
                    swap(matrix[x][y], matrix[cur_x][cur_y]);
                }
            }
        }
    }
};