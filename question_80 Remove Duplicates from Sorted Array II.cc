class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 2){
            return n;
        }
        int idx=2, cur=2, pre_1=1, pre_2=0;
        while(cur < n){
            if(A[pre_1] == A[pre_2] && A[pre_1] == A[cur]){
                cur++;
            }else{
                A[idx] = A[cur];
                pre_2 = pre_1;
                pre_1 = idx;
                idx++;
                cur++;
            }
        }
            
        return idx;
    }
};