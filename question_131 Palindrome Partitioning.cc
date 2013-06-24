class Solution {
public:
    inline bool is_palindrome(const char* l, const char* r){
        while(l<r){
            if(*(l++)!=*(r--))
                return false;
        }
        return true;
    }
    
    
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> result;
        set<vector<string>> duplicate;
        int nlen = s.length();
        const char* str = s.c_str();
        for(int idx=0; idx<nlen; ++idx){
            string curChar;
            curChar += s[idx];
            duplicate.clear();
            for(int i=result.size()-1; i>=0; --i){              
                result[i].push_back(curChar);
                int offset = 1;
                for(int j=result[i].size()-2; j>0; --j){
                    offset += result[i][j].size();
                    if(result[i][j][0] == str[idx] && is_palindrome(str+idx-offset+1, str+idx)){
                        vector<string> tmp;
                        for(int n=0; n<j; ++n){
                            tmp.push_back(result[i][n]);
                        }
                        tmp.push_back(s.substr(idx-offset+1, offset));
                        if(duplicate.count(tmp) == 0){
                            result.push_back(tmp);
                            duplicate.insert(tmp);
                        }
                        break;
                    }
                }   
            }
            if(is_palindrome(str, str+idx)){
                result.push_back(vector<string>());
                result.back().push_back(s.substr(0, idx+1));
            }
        }
        return result;
    }
};