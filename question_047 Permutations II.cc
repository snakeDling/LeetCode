//不用set的，貌似没快多少……
class Solution {
public:
    vector<vector<int> > result;
    void premute(vector<int> &num, int k, int n){
        if(n == k){
            result.push_back(num);
        }
        for(int i=k;i<n;i++){
            if(k == i || num[k] != num[i]){
                swap(num[k],num[i]);
                premute(num, k+1,n);
                swap(num[i],num[k]);
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
//        sort(num,begin(), num.end());
        premute(num, 0, num.size());
//        return vector<vector<int>>(result.begin(), result.end());
        return result;
    }
};

//用set版
class Solution {
public:
    set<vector<int> > result;
    void premute(vector<int> &num, int k, int n){
        if(n == k){
            result.insert(num);
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
        return vector<vector<int>>(result.begin(), result.end());
    }
};