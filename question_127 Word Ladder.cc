//N遍历版本，虽然过了，但其实还是很慢，和枚举的比起来……不过过了没超时~
class Solution {
public:
    inline int _distance(const string& l, const string& r){
        int distance = 0;
        const char* l_s = l.c_str();
    	const char* r_s = r.c_str();
    	for(int i=l.size()-1; i>=0; --i){
    		distance+= (r_s[i] == l_s[i]) ? 0 : 1;
    	}
    	return distance;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	int result;
    	if(1 >= (result = _distance(start, end)))
    		return result+result;
    	//初始化数据    
    	vector<vector<string> > dtc(1000, vector<string>());
    	for(unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); it++){
    		dtc[_distance(start, *it)].push_back(*it);
    	}
    	if(dict.find(end) == dict.end()){
    		dtc[1].push_back(end);
    	}
    	//开始算距离
    	int cur = 0;
    	while(!dtc[cur++].empty()){
    		while(cur+1 >= dtc.size()){
    			dtc.push_back(vector<string>());
    		}
    		vector<string> tmp;
    		swap(dtc[cur], tmp); 
    		for(int i = tmp.size()-1; i>=0; --i){
    			int min_dis = start.size();
    			for(int j = dtc[cur-1].size()-1; j>=0; --j){
    				int _dis = _distance(tmp[i], dtc[cur-1][j]);
    				if(_dis == 1){
    					if(_distance(tmp[i], end) == 0){
    						return cur+1;
    					}else{
    						min_dis = 1;
    						break;
    					}
    				}
    				min_dis = min_dis<_dis ? min_dis : _dis;
    			}
    			dtc[cur+min_dis-1].push_back(tmp[i]);
    		}
    	}
    	return 0;
    }
};


//按照400ms代码改的，记录了每层的值，速度边800了。。。
void get_ladder_dp(const string start, const string end, unordered_set<string> &dict, vector<vector<string>> &DPs){
    DPs.push_back(vector<string>());
	int levl = 0;
	DPs[levl].push_back(start);
	dict.erase(start);
	while(dict.count(end) == 1 && !DPs[levl].empty()){
		++levl;
		DPs.push_back(vector<string>());
		for(int j=DPs[levl-1].size()-1; j>=0; --j){
			string tmp = DPs[levl-1][j];
			for(int i=tmp.length()-1; i>=0; --i){
				char back = tmp[i];
				for(tmp[i] = 'a'; tmp[i] <= 'z'; ++tmp[i]){
					auto ret = dict.find(tmp);
					if (tmp[i] != back && dict.erase(tmp) == 1)
						DPs[levl].push_back(tmp);
				}
				tmp[i] = back;
			}
		}
	}
}