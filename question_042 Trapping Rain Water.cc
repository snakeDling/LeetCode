    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0, r=n-1, count=0, l_hight=0 ,r_hight=0;
        while(l<r){
            if(A[l] < A[r]){
                if(A[l] < l_hight)
                    count += l_hight - A[l];
                else
                    l_hight = A[l];
                ++l;
            }else{
                if(A[r] < r_hight)
                    count += r_hight - A[r];
                else
                    r_hight = A[r];
                --r;
            }
        }
        return count;
    }
//疯狂精简版
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0, r=n-1, count=0, l_hight=0, r_hight=0;
        while(l<r){
            if(A[l] < A[r]){
                l_hight = max(A[l], l_hight);
                count += l_hight - A[l++];
            }else{
                r_hight = max(A[r], r_hight);
                count += r_hight - A[r--];
            }
        }
        return count;
    }
};