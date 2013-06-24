    vector<vector<int> > subsets(vector<int>&S, int nlen){
        vector<vector<int> > result;
        if(nlen<0){
           result.push_back(vector<int>());
           return result;
        }
        result = subsets(S, nlen-1);
        int count = result.size();
        vector<int> tmp;
        for(int i=0; i<count; ++i){
            tmp.clear();
            tmp=result[i];
            tmp.push_back(S[nlen]);
            result.push_back(tmp);
        }
        return result;      
    }

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        return subsets(S, S.size()-1);
    }