class Solution {
public:
    inline int _atoi(const char* s){
        if(*s == '0' && s[1] != '\0')
            return 256;
        else
            return atoi(s);
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        int nlen = s.length(),num;
        for(int p1=1; p1<=3&&p1+2<nlen;++p1){
            num = _atoi(s.substr(0,p1).c_str());
            if(num > 255) continue;
            for(int p2=1; p2<=3&&p2+p1+1<nlen;++p2){
                num = _atoi(s.substr(p1,p2).c_str());
                if(num > 255) continue;
                for(int p3=1; p3<=3&&p3+p2+p1<nlen; ++p3){
                    num = _atoi(s.substr(p1+p2,p3).c_str());
                    if(num > 255) continue;
                    num = _atoi(s.substr(p1+p2+p3).c_str());
                    if(num > 255) continue;
                    string tmp=s;
                    tmp.insert(p1, ".");
                    tmp.insert(p1+p2+1, ".");
                    tmp.insert(p1+p2+p3+2, ".");
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};