    class Solution {  
    public:  
        void prepare(string str, string &new_str){  
            new_str = "@";  
            new_str +="#";  
            for(int i=0;i<str.length();i++){  
                new_str += str[i];  
                new_str += "#";  
            }  
        }  
          
        string longestPalindrome(string s) {  
            // Start typing your C/C++ solution below  
            // DO NOT write int main() function  
            string str;  
            prepare(s, str);  
            int str_len = str.length();  
            str_len += "$";  
            int * p = new int[str_len];  
            memset(p,0,sizeof(int)*str_len);  
            int max=0;  
            int mid=0;  
            for(int i=0;i<str_len;i++){  
                if(max > i){  
                    p[i] = min(p[2*mid-i], p[mid]+mid-i);  //此处这样做，其实造成的后果是，P[]这个array已经不再是严格的每个值都是真的这个pos的回文长度+1了。其代表的是，这个点的回文值小于或等于这个值，但是因为他不会大过mx，所以不是准确值也木有关系~  
                }else{  
                    p[i] = 1;  
                }  
                while(str[p[i]+i] == str[i-p[i]]){  
                    p[i]++;  
                }  
                if(p[mid]+i>max){  
                    max = p[mid] + i;  
                    mid = i;  
                }  
            }  
            max = 0;  
            mid = 0;  
            for(int i=0;i<str_len;i++){  
                if(p[i]>max){  
                    max = p[i];  
                    mid = i;  
                }  
            }  
            max--;  
            mid = (mid)/2 - 1;  
            string sub;  
            for(int i = mid - (max-1)/2; i<=mid + (max-1)/2 + (max+1)%2; i++){  
                sub += s[i];  
            }  
            delete[] p;  
            return sub;  
        }  
    };  