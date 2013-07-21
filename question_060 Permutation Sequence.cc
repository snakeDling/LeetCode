class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        vector<int> num(n);
        int total =1, idx;
        for(int i=1; i<=n; ++i){
            num[i-1] = i;
            total *= i; 
        }
        for(int i=n; i>=1; --i){
            total = total/i;
            idx = (k-1)/total;
            k = k - idx * total;
            result.push_back('0' + num[idx]);
            num.erase(num.begin() + idx);
        }
        return result;
    }
};