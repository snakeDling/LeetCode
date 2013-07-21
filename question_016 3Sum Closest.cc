class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int ret = num[0] + num[1] + num[2];
        for(int i=num.size()-1; i>1; --i){
            int subSum = num[i];
            int j = i-1, k=0;
            while(j > k){
                int sum = num[j] + num[k] + subSum;
                if(abs(ret - target) > abs(sum - target)) ret = sum;
                if(sum == target) return target;
                if(sum > target){
                    j--;
                }else{
                    k++;
                }
            }
        }
        return ret;
    }
};