    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int num=0, pre=0, result=0;
        for(int i=s.size()-1; i>=0; --i, pre=num){
            num = map[s[i]];
            if(pre > num)
                result -= num;
            else
                result += num;
        }
        return result;
    }