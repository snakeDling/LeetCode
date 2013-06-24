class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(digits.begin(), digits.end());
        bool plus=true;
        int i=0;
        digits.push_back(0);
        while(plus){
            digits[i] = (digits[i]+1==10) ? 0 : digits[i]+1;
            plus = digits[i++] == 0;
        }
        if(digits.back() == 0)
            digits.pop_back();
        reverse(digits.begin(), digits.end());
        return digits;
    }
};