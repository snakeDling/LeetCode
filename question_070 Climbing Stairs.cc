class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[3]={0,1,0};
        for(int i=1; i<=n; ++i, dp[2]=dp[1], dp[1]=dp[0]){
            dp[0]=dp[1]+dp[2];
        }
        return dp[0];
    }
};