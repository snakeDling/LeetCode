class Solution {
public:
    void add_two_strings(string &dest, string& add){
        int nlen = max(dest.size(), add.size());
        dest.resize(nlen, '0');
        add.resize(nlen, '0');
        int carry=0;
        for(int i=0; i<nlen; ++i){
            int cur_num = dest[i] + add[i] -2*'0' + carry;
            carry = cur_num/10;
            cur_num = cur_num%10;
            dest[i] = cur_num + '0';
        }
        if(carry > 0){
            dest.push_back(carry + '0');
        }
    }
    
    void multi_string_num(const string &dest, int multiplier, string& ret){

        int nlen = dest.size(), carry = 0;
        for(int i=0; i<nlen; ++i){
            int _num = (dest[i]-'0') * multiplier + carry;
            carry = _num/10;
            _num = _num%10;
            ret.push_back(_num + '0');
        }
        if(carry > 0){
            ret.push_back(carry + '0');
        }
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1.size()<num2.size())
            num1.swap(num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result, tmp;
        for(int i=0; i<num2.size(); ++i){
            if(num2[i] == '0')
                continue;
            tmp.clear();
            tmp.resize(i,'0');
            multi_string_num(num1, num2[i]-'0', tmp);
            add_two_strings(result, tmp);
        }
        if(result.empty()){
            return "0";
        }else{
            reverse(result.begin(), result.end());
            return result;
        }
    }
};