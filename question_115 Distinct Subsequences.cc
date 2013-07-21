//dp优化版，优化的我泪流满面，基础还是太弱啊…
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int diff = S.size() - T.size()+1;
        if(S.empty() || diff <= 0)
            return 0;
        vector<int> dp(diff+1, 1);
        dp[0] = 0;
        for(int i=0; i<T.size(); ++i){
            for(int j=1; j<=diff; ++j){
                dp[j] = dp[j-1] + (T[i] == S[i+j-1] ? dp[j] : 0);
            }
        }
        return dp[diff];
    }
};

//dp未优化版本，难看的代码
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int diff = S.size() - T.size()+1;
        if(S.empty() || diff <= 0)
            return 0;
        vector<vector<int>> dp(T.size(), vector<int>(S.size(), 0));
        dp[0][0] = (S[0] == T[0] ? 1 : 0);
        for(int i=1; i< S.size(); ++i){
            dp[0][i] = dp[0][i-1];
            if(S[i] == T[0])
                ++dp[0][i];
        }
        for(int i=1; i<T.size(); ++i){
            for(int j=1; j<S.size(); ++j){
                dp[i][j] = dp[i][j-1] + (T[i] == S[j] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[T.size()-1][S.size()-1];
    }
};
