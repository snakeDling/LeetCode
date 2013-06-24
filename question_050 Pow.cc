    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double tmp= (n>=0)? x:((double)1)/x;
        double result=1;
        unsigned int un = abs(n);
        for(int i=0;i<30;i++){
            if(((un<<(31-i))>>31)&1){
                result *= tmp;
            }
            tmp = tmp*tmp;
        }
        return result;
    }