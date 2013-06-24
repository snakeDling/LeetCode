class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = 0x80000000;
        int sum = 0;
        for(int i=0; i<n; ++i){
            sum += A[i];
            if(sum < 0){
                maxSum = max(A[i], maxSum);
                sum = 0;
            }else{
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};