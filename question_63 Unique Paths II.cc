class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=obstacleGrid.size(), n=obstacleGrid[0].size(), dp[n];
        dp[0]= obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i=1; i<n; ++i){
            dp[i] = obstacleGrid[0][i] == 1 ? 0 : dp[i-1];
        }
        for(int i=1; i<m; ++i){
            dp[0] = obstacleGrid[i][0] == 1 ? 0 : dp[0];
            for(int j=1; j<n; ++j){
                dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};