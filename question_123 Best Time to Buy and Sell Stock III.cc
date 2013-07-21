        /****
        这个思路本质上是把问题转化为了前M大最大和子序列的求解
        i意味着第i个price，j表示购买几次，即求前j个最大子序列
        dp[i][j] = max(dp[i-1][j], max(dp[0][j-1],dp[1][j-1],....,dp[i-1][j-1]) ) + diff;
        ***/
    int maxProfit(vector<int> &prices, int m){
        int profit=0, i=1, nlen=prices.size();
        vector<int> dp(m+1,0);
        vector<int> segMax(m+1, 0);
        for(; i<m && i< nlen; ++i){
            segMax[i] = dp[i] = max(dp[i-1], dp[i-1]+prices[i]-prices[i-1]);
        }
        for(; i<nlen; ++i){
            for(int j=m; j>0; --j){
                dp[j] = max(dp[j], segMax[j-1]) + prices[i] - prices[i-1];
                segMax[j] = max(segMax[j], dp[j]);
            }
        }
        for(i=0; i<=m; ++i){
            profit = max(profit, segMax[i]);
        }
        return profit;
    }b
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        /****
        这个思路本质上是把问题转化为了前M大最大和子序列的求解
        i意味着第i个price，j表示购买几次，即求前j个最大子序列
        dp[i][j] = max(dp[i-1][j], max(dp[0][j-1],dp[1][j-1],....,dp[i-1][j-1]) ) + diff;
        ***/
        return maxProfit(prices, m);
    }