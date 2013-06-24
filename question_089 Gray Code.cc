class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(1,0);
        for(int i=0; i<n; ++i){
            for(int j=result.size()-1; j>=0; --j){
                result.push_back((1<<i) + result[j]);
            }
        }
        return result;
    }
};