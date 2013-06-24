//dp优化版 原dp公式： dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + word1[i]==word[j]?0：1)
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[word2.size()+1];
        for(int i=word2.size(), j=0; i>=0; --i){
            dp[i] = j++;
        }
        for(int i=word1.size(); i>=0; --i){
            int tmp = dp[word2.size()];
            dp[word2.size()] = word1.size()-i;
            for(int j=word2.size()-1; j>=0; --j){
                int replace = tmp+(word1[i]==word2[j] ? 0:1);
                tmp = dp[j];
                dp[j] = min(dp[j]+1, min(dp[j+1]+1, replace));
            }
        }
        return dp[0];
    }
};