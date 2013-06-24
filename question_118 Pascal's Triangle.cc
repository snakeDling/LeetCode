class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        result.resize(numRows);
        result[0].push_back(1);
        for(int i=1; i<numRows; ++i){
            result[i].push_back(result[i-1][0]);
            for(int j=1; j<i; ++j){
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result[i].push_back(result[i-1][i-1]);
        }
        return result;
    }
};