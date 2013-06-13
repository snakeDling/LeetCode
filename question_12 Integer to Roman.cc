class Solution {
public:
    const char buf[7][2]={"I","V","X","L","C","D","M"};
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        string tmp;
        string result;
        int pos = 0;
        while(num){
            if(num%10 == 9){
                tmp = buf[pos];
                tmp += buf[pos+2];
            }else if(num%5 == 4){
                tmp = buf[pos];
                tmp+= buf[pos+1];
            }else{
                if(num%10 >= 5)
                    tmp = buf[pos+1];
                else
                    tmp = "";
                for(int i=0; i<num%5; i++){
                    tmp += buf[pos];
                }
            }
            num = num/10;
            pos = pos+2;
            result = tmp + result;
        }
        return result;
    }
}; 