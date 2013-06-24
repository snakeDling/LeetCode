class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int reachPos=0;
        for(int i=0; i<n; ++i){
            if(reachPos < i){
                return false;
            }
            reachPos = max(reachPos, A[i]+i);
            if(reachPos>= n-1){
                return true;
            }
        }
        return false;
    }
};