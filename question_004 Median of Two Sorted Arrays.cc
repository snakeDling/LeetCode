    inline double mid(int A[], int n){  //查找中值  
        if(n%2 == 0)  
            return double(A[n>>1]+A[(n>>1)-1])*0.5;  
        else  
            return A[n>>1];  
    }  
    inline void insertSortArray(int A[], int n, int value){  //将数据插入数组并排序  
        for(int i=0; i<n; i++){  
            if(A[i] < value){  
                int tmp = value;  
                value = A[i];  
                A[i] = tmp;  
            }  
        }  
    }  
    inline double makeSortArray(int A[], int m, int B[], int n){  //制作最后小的短的处理数组  
        int arr[6] = {0};  
        //      memset(arr, 0, sizeof(int)*4);  
        for(int i=0;i<m;i++){  
            insertSortArray(arr, m, A[i]);  
        }  
        for(int i=0;i<n;i++){  
            insertSortArray(arr, m+n, B[i]);  
        }  
        return mid(arr, m+n);  
    }  
      
      
      
    double findMedianSortedArrays(int A[], int m, int B[], int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if(m>n) //保证m<n  
            return findMedianSortedArrays(B,n,A,m);  
      
        if(m == 0)  
            return mid(B, n);  
        if(n == 0)  
            return mid(A, m);  
        if(m == 1){  
            if(n == 1)  
                return double(A[0]+B[0])*0.5;  
            if(n%2==0)  
                return A[0] > B[n>>1] ? B[n>>1]: A[0] < B[(n>>1)-1] ? B[(n>>1)-1] : A[0];  
            else{  
                return makeSortArray(A, m, &B[(n>>1)-1], 3);  
            }  
      
        }  
        if(m ==2){  
            if(n == 2)  
                return makeSortArray(A,m,B,n);  
            else  
                return makeSortArray(A,m,B+((n-1)>>1)-1, 4-(n%2));  
        }  
      
        double mid_a = mid(A, m);  
        double mid_b = mid(B, n);  
        int remove_len = ((m-1)>>1);  
        if(mid_a > mid_b)  
            return findMedianSortedArrays(A, m-remove_len, B+remove_len, n-remove_len);  
        else if(mid_a < mid_b)  
            return findMedianSortedArrays(A+remove_len, m-remove_len, B, n-remove_len);  
        else  //如果mid_a == mid_b则标志这已经是中值了  
            return mid_a;    
    }  