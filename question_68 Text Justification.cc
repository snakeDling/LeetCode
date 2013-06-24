class Solution {
public:
    inline string make_line(vector<string> &words, int start, int end, int count, int L, bool bEnd){
        string result;
        if(start < end){
            int spaceCount = (L-count)/(end-start);
            for(int i=start; i<end; ++i){
                result+=words[i];
                if(!bEnd){
                    for(int j=0; j<spaceCount; ++j){
                        result += " ";
                    }
                    if(i-start <(L - count)%(end-start)){
                        result += " ";
                    }
                }else{
                    result += " ";
                }
            }
            result += words[end];
        }else{
            result += words[start];
        }
        while(result.length() < L){
            result += " ";
        }
        return result;
    }

    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        int nlen = words.size(), count=0, start=0;
        for(int i=0; i<nlen; ++i){
            if(count + words[i].length() + i - start > L){
                result.push_back(make_line(words, start, i-1, count, L, false));
                start = i;
                count = words[i].length();
            }else{
                count += words[i].length();
            }
        }
        if(start <= nlen-1){
            result.push_back(make_line(words, start, nlen-1, count, L, true));
        }
        return result;
    }
};