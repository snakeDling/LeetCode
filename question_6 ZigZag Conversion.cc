    class Solution {  
    public:  
        void apend(string &dst, string &src, int pos, int s_len){  
            if(pos < s_len)  
                dst += src[pos];  
        }  
          
        string convert(string s, int nRows) {  
            // Start typing your C/C++ solution below  
            // DO NOT write int main() function      
            string* array = new string[nRows];  
            int nlen = s.length();  
            int j=0;  
            while(j<nlen){  
                for(int i=0;i<nRows;i++){  
                    apend(array[i], s, j++, nlen);  
                }  
                for(int i=nRows-2; i>0;i--){  
                    apend(array[i], s, j++, nlen);  
                }  
            }  
            string result;  
            for(int i=0;i<nRows;i++){  
                result += array[i];  
            }  
            delete[] array;  
            return result;  
        }  
    };  