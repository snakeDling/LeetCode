class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count=0, reachPos=0, newReach=0;
        for(int i=0; i<n; ++i){
            if(reachPos < i){
                if(newReach<i)
                    return 0;
                ++count;
                reachPos = newReach;
                if(reachPos>= n-1){
                    break;
                }
            }
            newReach = max(newReach, A[i]+i);

        }
        return count;
    }
};