    bool isPalindrome(int x) {  
        if (x < 0) return false;  
        int div = 1;  
        while (x / div >= 10) {  
            div *= 10;  
        }  
        while (x != 0) {  
            int l = x / div;  
            int r = x % 10;  
            if (l != r) return false;  
            x = (x % div) / 10;  
            div /= 100;  
        }  
        return true;  
    }  

//炫耀版，完全没有实际意义。
    bool isPalindrome(int x, int &y) {  
        if (x < 0) return false;  
        if (x == 0) return true;  
        if (isPalindrome(x/10, y) && (x%10 == y%10)) {  
            y /= 10;  
            return true;  
        } else {  
            return false;  
        }  
    }  
    bool isPalindrome(int x) {  
        return isPalindrome(x, x);  
    }  