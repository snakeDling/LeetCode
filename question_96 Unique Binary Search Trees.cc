    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* buf= new int[n+1];
        buf[0] = buf[1] = 1;
        for(int i=2; i<=n; ++i){
            buf[i] = 0;
            for(int j=(i-1)/2; j>=0; --j){
                buf[i] += buf[j]*buf[i-1-j];
            }
            buf[i] += buf[i];
            if(i%2 == 1)    
                buf[i] -= buf[i/2]*buf[i/2];
        }
        int result = buf[n];
        delete[] buf;
        return result;
    }