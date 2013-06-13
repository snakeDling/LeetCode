    void _swap(int i, int j, vector<int> &num){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    void reversal(int n , vector<int> &num){
        int nlen = num.size()-1;
        for(int i = (num.size()-n)/2-1; i>=0; --i){
            _swap(n+i, nlen-i, num);
        }
    }
    
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = num.size()-1;
        for(int pre = i; i>=0; pre=i--){
            if(num[i]<num[pre]){
                int j = num.size()-1;
                while(num[j]<=num[i]){--j;}
                _swap(i, j, num);
                break;
            }
        }
        reversal(++i, num);
    }