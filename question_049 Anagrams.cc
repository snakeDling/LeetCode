//能保证稳过的写法
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, string> map;
        vector<string> result;
        string tmp;
        while(!strs.empty()){
            tmp = strs.back();
            sort(tmp.begin(), tmp.end());
            auto it = map.find(tmp);
            if(it == map.end()){
                map[tmp] = strs.back();
            }else{
                if(it->second[0] != '1'){
                    result.push_back(it->second);
                    it->second[0] = '1';
                }
                result.push_back(strs.back());
            }
            strs.pop_back();
        }
        return result;
    }
};


//不能保证稳过的写法，速度稍快
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hash[26];
        vector<string> result;
        unordered_map<long long, string> map;
        while(!strs.empty()){
            memset(hash, 0, sizeof(int)*26);
            const char* str = strs.back().c_str();
            for(int i=strs.back().length()-1; i>=0; --i){
                ++hash[str[i]-'a'];
            }
            long long hash_val=0;
            for(int i=0; i<26; ++i){
                hash_val = ((hash_val*10) + hash[i]);
            }
            auto it = map.find(hash_val);
            if(it == map.end()){
                map[hash_val] = strs.back();
            }else{
                if(it->second[0] != '1'){
                    result.push_back(it->second);
                    it->second[0] = '1';
                }
                result.push_back(strs.back());
            }
            strs.pop_back();
        }
        return result;
    }
};