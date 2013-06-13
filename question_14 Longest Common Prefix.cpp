    string getLongest(vector<string> &strs){
        if(strs.empty())
            return "";
        string result;
        int pos = 0;
        while(true){
            char tag = strs[0][pos];
            for(int i=0; i<strs.size(); i++){
                if(strs[i][pos] == '\0' || strs[i][pos] != tag)
                    return result;
            }
            result += tag;
            pos++;
        }
    }


    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return getLongest(strs);
    }