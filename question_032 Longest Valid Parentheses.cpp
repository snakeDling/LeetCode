    int find_valid(const char* &s){
        int curLen = 0;
        while(*s != '\0'){
            if(*(s++) == ')'){
                return curLen+2;
            }else{  //*s == '('
                const char* s_tmp = s;
                int tmp =find_valid(s_tmp);
                if(tmp <= s_tmp - s ){
                    if(curLen < tmp)
                        curLen = tmp;
                    s = s_tmp;
                    return curLen;
                }else{
                    curLen += tmp;
                }
                s = s_tmp;
            }
        }
        return curLen;
    }

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* p = s.c_str();
        int max = 0;
        int curLen = 0;
        while(*p != '\0'){
            if(*(p++) == ')'){
                if(curLen > max){
                    max = curLen;
                }
                curLen = 0;
            }else{
                const char* p_2 = p;
                int tmp =find_valid(p_2);
                int tmp2 = p_2-p+1;
                if(tmp <(p_2-p+1)){
                    if(curLen > tmp){
                        if(curLen > max)
                            max = curLen;
                    }
                    curLen = tmp;
                }else{
                    curLen += tmp;
                }
                p = p_2;
            }
        }
        if(curLen > max)
            max = curLen;
        return max;
    }