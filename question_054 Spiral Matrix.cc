class Solution {
public:
    vector<int> result;
    void put_x(int x_s, int x_e, int y, vector<vector<int> > &matrix){
        if(x_s <= x_e)
            for(int i=x_s; i<=x_e;++i)
                result.push_back(matrix[y][i]);
        else
            for(int i = x_s; i>=x_e;--i)
                result.push_back(matrix[y][i]);
    }
    void put_y(int x, int y_s, int y_e, vector<vector<int> > &matrix){
        if(y_s <= y_e)
            for(int i=y_s; i<=y_e;++i)
                result.push_back(matrix[i][x]);
        else
            for(int i=y_s; i>=y_e;--i)
                result.push_back(matrix[i][x]);
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        int n = matrix.size();
        if(n == 0)
            return result;
        int m = matrix[0].size();
        if(m == 0)
            return result;
        int x_s=0,x_e=m-1,y_s=0,y_e=n-1;
        while(x_s<=x_e || y_s<=y_e){
            if(x_s<=x_e && y_s<=y_e)
                put_x(x_s, x_e, y_s, matrix);
            y_s++;
            if(y_s<=y_e && x_s<=x_e)
                put_y(x_e, y_s, y_e, matrix);
            x_e--;
            if(x_s<=x_e && y_s<=y_e)
                put_x(x_e, x_s, y_e, matrix);
            y_e--;
            if(y_s<=y_e && x_s<=x_e)
                put_y(x_s, y_e, y_s, matrix);
            x_s++;
        }
        return result;
    }
};