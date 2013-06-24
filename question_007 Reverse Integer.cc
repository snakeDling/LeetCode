    class Solution {  
    public:  
        int reverse(int x) {  
            // Start typing your C/C++ solution below  
            // DO NOT write int main() function  
            bool bNegative = x<0 ? true : false;  
            x = bNegative ? 0-x : x;  
            int result=0;  
            while(x){  
                result = result*10+x%10;  
                x = x/10;  
            }  
            result = bNegative? 0-result : result;  
            return result;  
        }  
    };   