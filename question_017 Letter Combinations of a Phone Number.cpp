    vector<string> find_result(const char* digits, vector<string> &index){
        vector<string> result;
        if(*digits == '\0'){
            result.push_back("");
            return result;
        }
        vector<string> pre = find_result(digits+1, index);
        int num = *digits - '0';
        int nlen = pre.size();
        result.resize(nlen*index[num].size());
        for(int j=0; j<index[num].size();j++){
            for(int i = 0; i < nlen; i++){
                result[j*nlen+i] = index[num][j] + pre[i];
            }
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> index(10);
        index[0] =" ";
        index[1] ="";
        index[2] ="abc";
        index[3] = "def";
        index[4] = "ghi";
        index[5] = "jkl";
        index[6] = "mno";
        index[7] = "pqrs";
        index[8] = "tuv";
        index[9] = "wxyz";
        return find_result(digits.c_str(), index);
    }