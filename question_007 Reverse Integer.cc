class Solution {
public:
    int reverse(int x) {
            bool bNegative = x<0 ? true : false;  
            x = bNegative ? 0-x : x; 
            if (x < 0) return 0;
            int result=0;  
            while(x){  
                if ((result*10+(x%10))/10 < result) return 0;
                result = result*10+x%10;  
                x = x/10;
            }  
            result = bNegative? 0-result : result;  
            return result;  
    }
};
