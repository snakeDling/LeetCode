//前向dp代码
//丧心病狂精简版
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty() || s[0] == '0')
            return 0;
        int p = 1, p_1 = 1, p_2 = 1;
        for(int i=1; i<s.size(); ++i, p_2=p_1, p_1=p){
            p = (s[0] == '0') ? 0 : p_1;
            p = (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) ? p + p_2 : p;
        }
        return p;
    }
