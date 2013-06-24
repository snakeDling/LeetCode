class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty() || matrix[0].empty())
            return;
        int n = matrix.size(), m=matrix[0].size(), x, y;
        for(y=0; y<m; ++y){
            if(matrix[0][y] == 0) break;
        }
        bool firstCulHasZero = y != m;
        for(y=0; y<m; ++y){
            for(x=0; x<n; ++x){
                if(matrix[x][y] == 0) break;
            }
            matrix[0][y] = x == n ? matrix[0][y] : 0;
        }
        for(x=1; x<n; ++x){
            for(y=0; y<m; ++y){
                if(matrix[x][y] == 0) break;
            }
            if(y == m){
                for(y=0; y<m; ++y){
                    matrix[x][y] = matrix[0][y] == 0 ? 0 : matrix[x][y];
                }
            }else{
                for(y=0; y<m; ++y){
                    matrix[x][y] = 0;
                }
            }
        }
        if(firstCulHasZero){
            for(y=0; y<m; ++y){
                matrix[0][y] = 0;
            }
        }
    }
};