class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(*s == '\0' && *p == '\0')
            return true;
        if(*p == '\0')
            return false;
        if(*(p+1) == '*'){
            while((*p == *s || *p == '.') && *s != '\0'){
                if(isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s,p+2);
        }
        
        if(*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s+1, p+1);
        else
            return false;

    }
}; 