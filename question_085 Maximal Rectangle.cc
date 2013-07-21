class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m=matrix[0].size();
        vector<int> height(m+1, 0);
        int maxArea=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    ++height[j];
            }
            stack<int> s;
            s.push(-1);
            int idx=0;
            while(idx <= m){
                if(s.size()==1 || height[s.top()] <= height[idx]){
                    s.push(idx++);
                }else{
                    int h = s.top();
                    s.pop();
                    maxArea = max(maxArea, height[h] * ( idx - s.top()-1));
                }
            }   
        }
        return maxArea;
    }
};