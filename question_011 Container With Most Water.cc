    class Solution {  
     public:  
         int maxArea(vector<int> &height) {  
             // Start typing your C/C++ solution below  
             // DO NOT write int main() function  
             int maxArea = 0, i = 0, j = height.size()-1;  
               
             while (i < j) {  
                 int area = min(height[i], height[j]) * (j-i);  
                 if (area > maxArea)  
                     maxArea = area;  
                       
                 if (height[i] < height[j])  
                     i++;  
                 else  
                     j--;  
             }  
               
             return maxArea;  
         }  
     };  