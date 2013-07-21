class Solution {
public:
    int* kmp_table(char *needle, int n){
        int *result = new int[n+1];
        result[0] = 0;
        result[1] = 0;
        for(int i=2; i<=n; ++i){
            if(needle[result[i-1]] == needle[i-1]){
                result[i] = result[i-1] + 1;
            }else{
                result[i] = 0;
            }
        }
        return result;
        
    }

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(haystack == NULL || needle == NULL)
            return NULL;
        int nlen = strlen(needle), i = 0;
        int *table = kmp_table(needle, nlen);
        while(*haystack!='\0' && i<nlen){
            if(*haystack != needle[i]){
                if(i == 0) haystack++;
                i = table[i];
            }else{
                ++i;
                haystack++;
            }
        }
        delete[] table;
        if(i >= nlen){
            return haystack - nlen;
        }else{
            return NULL;
        }
    }
};