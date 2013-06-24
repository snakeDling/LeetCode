class Solution {
public:
    string countAndSay(string pre, int n){
        if(n == 0)
            return pre;
        int count=1,i=0;
        string result;
        const char* c = pre.c_str();
        while(c[i] != '\0'){
            if(c[i] == c[i+1]){
                ++count;
            }else{
                result+=(count+'0');
                result+=c[i];
                count = 1;
            }
            ++i;
        }
        return countAndSay(result, n-1);
    }

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return countAndSay("1", n-1);
    }
};