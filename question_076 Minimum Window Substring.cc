    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num[256];
        memset(num, 0, sizeof(int)*256);
        int still_need = 0;
        for(int i=T.size()-1; i>=0; --i){
            --num[T[i]];
            --still_need;
        }
        int it_1=0, it_2=0;
        int s_len = S.size(), min_start=-1, min_len=S.size()+1;
        while(it_1 < s_len){
            while(it_1 < s_len && still_need <0){
                if(++num[S[it_1]] <= 0)
                    ++still_need;
                ++it_1;
            }
            while(still_need == 0){
                if(--num[S[it_2]] < 0){
                    --still_need;
                    if(min_len > it_1-it_2){
                        min_start = it_2;
                        min_len = it_1 - it_2;
                    }
                }
                ++it_2;
            }
        }
        return min_start==-1 ? "": S.substr(min_start, min_len);
    }