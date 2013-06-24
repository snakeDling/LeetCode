    vector<string> result;
    void generate(string pre, int nl, int nr){
        if(nl == 0 && nr == 0){
            result.push_back(pre);
            return;
        }
        if(nl<nr){
            generate(pre+")", nl, nr-1);
        }
        if(nl>0){
            generate(pre+"(", nl-1,nr);
        }
        
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        generate("", n, n);
        return result;
    }