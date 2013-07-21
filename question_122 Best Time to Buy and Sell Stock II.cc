class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0, buy=0x7FFFFFFF;
        for(int i=0 ; i<prices.size(); ++i){
            if(buy < prices[i]){
                profit += prices[i] - buy;
            }
            buy = prices[i];
        }
        return profit;
    }
};