class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<vector<int> > result;
        vector<int> sul(4,0);
        if(num.size() < 4)
            return vector<vector<int> >();
        sort(num.begin(), num.end());
        int idx[4] = {0};
        idx[3] = num.size()-1;
        for(; idx[3] > 2; idx[3]--){
            for(idx[2]=idx[3]-1; idx[2]>1; idx[2]--){
                int subSum = num[idx[2]] + num[idx[3]];
                idx[1] = idx[2]-1; idx[0] = 0;
                while(idx[1] > idx[0]){
                    int sum = num[idx[0]] + num[idx[1]] + subSum;
                    if(sum == target){
                        sul[0] = num[idx[0]];
                        sul[1] = num[idx[1]];
                        sul[2] = num[idx[2]];
                        sul[3] = num[idx[3]];
                        result.insert(sul);
                    }
                    if(sum > target){
                        idx[1]--;
                    }else{
                        idx[0]++;
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};