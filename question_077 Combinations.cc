class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        while(!path.empty()){
            ++path.back();
            if(path.back() > n-k+path.size()){
                path.pop_back();
            }else if(path.size() == k){
                result.push_back(path);
            }else{
                path.push_back(path.back());
            }
        }
        return result;
    }
};
