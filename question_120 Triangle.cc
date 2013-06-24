class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.empty())
            return 0;
        vector<int> dp = triangle.back();
        int tmp = 0;
        for(int i=triangle.size()-2; i>=0; --i){
            for(int j = triangle[i].size()-1; j>=0; --j){
                dp[j+1] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
            dp.erase(dp.begin());
        }
        return dp[0];
    }
};