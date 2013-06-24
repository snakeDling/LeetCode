class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count[3]={0};
        for(int i=0; i<n; ++i){
            ++count[A[i]];
        }
        int idx=0;
        for(int i=0; i<3; ++i){
            for(int j=0; j<count[i]; ++j){
                A[idx++] = i;
            }
        }
    }
};