class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(rowIndex+1, 1);
        int tmp;
        for(int i=1; i<=rowIndex; ++i){
            for(int j=i-2; j>=0; --j){
                tmp = dp[j+1] + dp[j];
                dp[j+1] = tmp;
            }
        }
        return dp;
    }
};