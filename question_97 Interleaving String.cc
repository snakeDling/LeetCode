//dp优化版。原dp公式：dp[i][j] = (dp[i+1][j] && s3[i+j]==s1[i]) || (dp[i][j+1] && s3[i+j]==s2[j])
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if(s1.length()+s2.length() != s3.length())
            return false;
        bool dp[s2.length()+1];
        memset(dp, 0, sizeof(bool)*(s2.length()+1));
        dp[s2.length()] = s1.back()==s3.back() || s2.back()==s3.back();
        for(int i=s1.length(); i>=0; --i){
            for(int j=s2.length()-1; j>=0; --j){
                dp[j] = (dp[j] && s3[i+j]==s1[i]) || (dp[j+1] && s3[i+j]==s2[j]);
            }
             
        }
        return dp[0];
    }
};
