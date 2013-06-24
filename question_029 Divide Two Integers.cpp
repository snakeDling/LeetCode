    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(divisor == 0 || dividend == 0)
            return 0;
        bool bNeg = (dividend>0)!=(divisor>0);
        long long dvd = dividend>0?dividend:-(long long)dividend;   //必须强转，否则负数边界-2147483648处理不正确
        long long dvr = divisor>0?divisor:-(long long)divisor;
        long long result = 0;
        for(int i=31; i>=0; --i){
            if(dvd - (dvr<<i) >= 0){
                result += 1<<i;
                dvd -= dvr<<i;
            }
        }
        return bNeg? -result:result;
    }
    
    //优雅的写法，不用long long
        int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(divisor == 0 || dividend == 0)
            return 0;
        bool bNeg = (dividend>0)!=(divisor>0);
        unsigned int dvd = dividend>0?dividend:-(long long)dividend;
        unsigned int dvr = divisor>0?divisor:-(long long)divisor;
        unsigned int result = 0;
        for(int i=31; i>=0; --i){
            if((dvd>>i) >= dvr){
                result += 1<<i;
                dvd -= dvr<<i;
            }
        }
        return bNeg? -result:result;
    }
    