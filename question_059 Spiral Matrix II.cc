class Solution {
public:
    int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result(n,vector<int>(n,0));
        int count=1,x=0,y=0;
        for(; n >=2; n-=2, x++, y++){
            int cur_offset = 0;
            for(int i=0; i<4; i++){
                for(int j=0;j<n-1;j++){
                    result[x][y] = count++;
                    x += offset[cur_offset][1];
                    y += offset[cur_offset][0];
                }
                cur_offset++;
            }
        }
        if(n == 1){
            result[x][y] = count;
        }
        return result;
    }

};