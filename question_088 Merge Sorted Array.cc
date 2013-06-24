//进来数组可以各种方向，只要有序，然后出去的为升序数组
    int get_sign(int A[], int n){
        for(int i=0; i< n; ++i){
            if(A[0] < A[i])
                return 1;   //由小到大
            else if(A[0] > A[i])
                return -1;  //由大到小
        }
        return 1;
    }

    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign_a = get_sign(A, m);
        int sign_b = get_sign(B, n);
        int it_a = sign_a>0 ? m-1 : 0, it_b = sign_b>0 ? n-1 : 0;
        int end_a = sign_a>0 ? -1 : m, end_b = sign_b>0 ? -1 : n;
        for(int i= m+n-1; i>=0; --i){
            if(it_a!=end_a && (it_b == end_b || A[it_a] > B[it_b])){
                A[i] = A[it_a];
                it_a -= sign_a;
            }else{
                A[i] = B[it_b];
                it_b -= sign_b;
            }
        }
    }