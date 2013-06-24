//前向靠谱版
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int r = 0;
        while(*s) {
            if(*(s++) != ' ')
                ++r;
            else if(*s != '\0' && *s != ' ')
                r = 0;
        }
        return r;
    }
};

//后向不靠谱版
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* s_r = s + strlen(s);
        while(s_r >= s && *(--s_r) ==' '){};
        const char* lastEnd = s_r;
        while(s_r >= s && *(--s_r) != ' '){};
        return lastEnd < s ? 0 : lastEnd - s_r;
    }
};