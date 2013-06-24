//浮点牛顿逼近法
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double t = 1;
        double r = x;  //t - (t*t-x)/(2*t)
        while(fabs(t-r) > 0.000001){
            t = r;
            r = (t + x/t)/2.0;
            
        }
        return t;
    }
    
//整数牛顿逼近法
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long t = x;
        while(t*t > x){
    		t  = (t+x/t)>>1;
    	}
    	return t;
    }