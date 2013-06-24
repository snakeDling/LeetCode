class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        int idx_a = a.size()-1, idx_b = b.size()-1, sum=0;
        while(idx_a>=0 && idx_b >=0){
            sum += a[idx_a--] - '0';
            sum += b[idx_b--] - '0';
            result+=((sum%2) + '0');
            sum = sum/2;
        }
        while(idx_a>=0){
            sum += a[idx_a--] - '0';
            result+=((sum%2) + '0');
            sum = sum/2;
        }
        while(idx_b>=0){
            sum += b[idx_b--] - '0';
            result+=((sum%2) + '0');
            sum = sum/2;
        }
        if(sum > 0)
            result+=(sum + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};