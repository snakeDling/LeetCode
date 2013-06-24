class Solution {  
public:  
    bool search(int A[], int n, int target) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int l=0;  
        int r=n-1;  
        while(r>=l){  
              
            if(A[l] == target || A[r] == target)  
                return true;  
            while(l<r && A[r] == A[l]) ++l;  
            if(A[l] == target)  
                return true;  
                  
            int mid = l+((r-l)>>1);  
            if(A[mid] > target){  
                if(A[l] > target && A[mid] >= A[l])  
                    l = mid+1;  
                else  
                    r = mid-1;  
            }else if(A[mid] < target){  
                if(A[r] < target && A[mid] <= A[r])  
                    r = mid-1;  
                else  
                    l = mid+1;  
            }else  
                return true;  
        }  
        return false;  
    }  