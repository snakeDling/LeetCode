class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0, buy_max=0, buy_min = buy_max, i=0;
        for(int i=prices.size()-1; i>=0; --i){
            if(buy_max < prices[i]){
                profit = max(buy_max-buy_min, profit);
                buy_min = buy_max = prices[i];
            }
            buy_min = min(prices[i], buy_min);
        }
        return max(profit, buy_max-buy_min);
    }
};