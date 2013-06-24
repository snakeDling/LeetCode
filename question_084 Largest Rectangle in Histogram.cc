class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        height.push_back(0);
        s.push(-1);
        int max_area = height[0], idx=0;
        int idx_end = height.size();
        while(idx < idx_end){
            if(s.size()==1 || height[s.top()] <= height[idx]){
                s.push(idx++);
            }else{
                int h = s.top();
                s.pop();
                max_area = max(max_area, height[h] * ( idx - s.top()-1));
            }
        }
        return max_area;
    }
};