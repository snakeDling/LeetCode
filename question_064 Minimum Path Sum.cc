class Solution {
public:
//    int minPath, m, n;
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(grid.empty() || grid[0].empty())
            return 0;
        int m=grid.size()-1, n=grid[0].size()-1;
        int dp[n+1];
        dp[n] = grid[m][n];
        for(int i=n-1; i>=0; --i){
            dp[i] = grid[m][i] + dp[i+1];
        }
        for(int x=m-1; x>=0; --x){
            dp[n] = dp[n] + grid[x][n];
            for(int y=n-1; y>=0; --y){
                dp[y] = min(dp[y+1], dp[y]) + grid[x][y];
            }
        }
        return dp[0];
    }
};