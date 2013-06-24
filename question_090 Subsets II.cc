class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result(1);
        sort(S.begin(), S.end());
        set<vector<int>> tmp;
        for(int i=0; i<S.size(); i++){
            for(int j=result.size()-1; j>=0; --j){
                tmp.insert(result[j]);
                result[j].push_back(S[i]);
                tmp.insert(result[j]);
            }
            result.clear();
            result.assign(tmp.begin(), tmp.end());
        }
        return result;
    }
};