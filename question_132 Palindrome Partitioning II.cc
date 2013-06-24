//真正的dp
class Solution {
public:
    int minCut(string str){

        int leng = str.size();

        int dp[leng+1];
        bool palin[leng][leng];

      for(int i = 0; i <= leng; i++)
        dp[i] = leng-i;
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;

      for(int i = leng-1; i >= 0; i--){
        for(int j = i; j < leng; j++){
          if(str[i] == str[j] && (j-i<2 || palin[i+1][j-1])){
            palin[i][j] = true;
            dp[i] = min(dp[i],dp[j+1]+1);
          }
        }
      }
      return dp[0]-1;
    }
};

//很烂的dp
class Solution {
public:
    inline bool is_palindrome(const char* l, const char* r){
        while(l<r){
            if(*(l++)!=*(r--))
                return false;
        }
        return true;
    }
    
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int nlen = s.size();        
        int* dp = new int[nlen];
        const char* str = s.c_str();
        dp[0] = 0;
        for(int i=1; i<nlen; ++i){
            dp[i] = dp[i-1] + 1;
            if(is_palindrome(str,str+i)){
                dp[i]=0;
                continue;
            }
            for(int j=1; j<i; ++j){
                if(is_palindrome(str+j, str+i)){
                    dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        int result = dp[nlen-1];
        delete[] dp;
        return result;
    }
};