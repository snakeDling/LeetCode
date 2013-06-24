class Solution {
public:
    void get_alphanumeric(string &s, string &result){
        int nlen = s.length();
        for(int i=0; i<nlen; ++i){
            if((s[i]<='Z' && s[i]>='A') || (s[i]<='9' && s[i]>='0'))
                result += s[i];
        }
    }

    void uper_letters(string &s){
        for(int i=s.length()-1; i>=0; --i){
            if(s[i] <= 'z' && s[i] >='a'){
                s[i] += 'A' - 'a';
            }
        }
        
    }

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        uper_letters(s);
        string cmp;
        get_alphanumeric(s, cmp);
        string cmp_opp = cmp;
        reverse(cmp_opp.begin(), cmp_opp.end());
        return strcmp(cmp.c_str(), cmp_opp.c_str()) == 0;
    }
};