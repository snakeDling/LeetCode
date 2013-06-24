class Solution {
public:
    int search_low(int A[], int n, int target){
        int l=0, r=n-1, mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(A[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
    int search_high(int A[], int n, int target){
        int l=0, r=n-1, mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(A[mid] <= target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2,-1);
        int l = search_low(A, n, target);
        if(A[l] == target){
            result[0] = l;
            result[1] = search_high(A, n, target);
        }
        return result;
    }
};