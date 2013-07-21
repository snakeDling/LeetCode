class Solution {
public:
    vector<vector<int> > result;
    void premute(vector<int> &num, int k, int n){
        if(n == k){
            result.push_back(num);
        }
        for(int i=k;i<n;i++){
            swap(num[k],num[i]);
            premute(num, k+1,n);
            swap(num[i],num[k]);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        premute(num, 0, num.size());
        return result;
    }
};