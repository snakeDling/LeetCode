class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0, r=n-1;
        int mid=0;
        while(l<r){
            mid = l+(r-l)/2;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target)
                r = mid;
            else
                l = mid+1;
        }
        return A[r] >= target ? r : r+1;
    }
};