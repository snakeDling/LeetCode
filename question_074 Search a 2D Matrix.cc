class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty() || matrix[0].empty())
            return false;
        int l=0, r=matrix.size()-1, y, x;
        while(l<=r){
            y = l+(r-l)/2;
            if(matrix[y][0] == target)
                return true;
            if(matrix[y][0] < target){
                l = y+1;
            }else{
                r = y-1;
            }
        }
        if(r<0)
            return false;
        y = r;l=1;r=matrix[y].size()-1;
        while(l<=r){
            x = l+(r-l)/2;
            if(matrix[y][x] == target)
                return true;
            if(matrix[y][x] < target){
                l = x+1;
            }else{
                r = x-1;
            }
        }
        return false;
    }
};