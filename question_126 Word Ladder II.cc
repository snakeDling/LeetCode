////////////////////////////优化版本，基于正扫dp出来的结果进行N反扫，反扫耗时基本消除，速度明显提升，全部跑完800ms~
class Solution {
public:
    inline int _distance(const string& l, const string& r){
        int distance = 0;
        const char* l_s = l.c_str();
        const char* l_r = r.c_str();
    	for(int i=l.size()-1; i>=0; --i){
    		distance+= l_r[i] == l_s[i] ? 0 : 1;
    	}
    	return distance;
    }
    
    void get_ladder_dp(const char* start, const char* end, unordered_set<string> &dict, vector<unordered_set<const char*>> &DPs){
        unordered_set<const char*> added;
    	DPs.push_back(unordered_set<const char*>());
    	int cur_levl = 0;
    	added.insert(start);
    	DPs[cur_levl].insert(start);
    	while(DPs[cur_levl].count(end) == 0 && !DPs[cur_levl].empty()){
    		++cur_levl;
    		DPs.push_back(unordered_set<const char*>());
    		for(auto it = DPs[cur_levl-1].begin(); it != DPs[cur_levl-1].end(); it++){
    			string tmp = *it;
    			for(int i=tmp.length()-1; i>=0; --i){
    				char back = tmp[i];
    				for(tmp[i] = 'a'; tmp[i] <= 'z'; ++tmp[i]){
    					auto ret = dict.find(tmp);
    					if(ret != dict.end() && added.count(ret->c_str()) == 0){
    						DPs[cur_levl].insert(ret->c_str());
    						added.insert(ret->c_str());
    					}
    				}
    				tmp[i] = back;
    			}
    		}
    	}
    }

    void clip_ladder_dp(string start, string end, vector<unordered_set<const char*>> &DPs, vector<vector<string>> &result){
    //定义进来时result已经resize好了的，大小与DPs相同。    
    	result[DPs.size()-1].push_back(end);
    	for(int i=DPs.size()-2; i >=0; --i){
    		for(auto it=DPs[i].begin(); it != DPs[i].end(); ++it){
    			for(int j = result[i+1].size()-1; j>=0; --j){
    				if(_distance(result[i+1][j], *it) == 1){
    					result[i].push_back(*it);
    					break;
    				}
    			}
    		}
    	}
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<unordered_set<const char*>> DPs_form_start;
    	get_ladder_dp(dict.find(start)->c_str(), dict.find(end)->c_str(), dict, DPs_form_start);
        int max_levl = DPs_form_start.size();
        if(DPs_form_start[max_levl-1].empty()){
            return vector<vector<string>>();
        }
        vector<vector<string>> dp(max_levl, vector<string>());
    	clip_ladder_dp(start, end, DPs_form_start, dp);
		//根据dp合并答案
    	vector<vector<string>> result(1,vector<string>(1,start)), tmp;
    	for(int levl = 1; levl < max_levl; ++levl){
    		for (int i = result.size()-1; i>=0; --i)	{
    			string cur = result[i][result[i].size()-1];
    			for (int j=dp[levl].size()-1; j>=0; --j){
    				if(_distance(cur, dp[levl][j]) == 1){
    					tmp.push_back(result[i]);
    					tmp.back().push_back(dp[levl][j]);
    				}
    			}
    		}
    		swap(result, tmp);
    		tmp.clear();
    	}
        return result;
    }
};


////////////////////////////基于Word LadderI 修改的代码，未优化，代码仍然相对简单易懂~
class Solution {
public:
    void get_ladder_dp(const char* start, const char* end, unordered_set<string> &dict, vector<unordered_set<const char*>> &DPs){
        unordered_set<const char*> added;
        DPs.push_back(unordered_set<const char*>());
    	int cur_levl = 0;
    	added.insert(start);
    	DPs[cur_levl].insert(start);
    	while(DPs[cur_levl].count(end) == 0 && !DPs[cur_levl].empty()){
    		++cur_levl;
    		DPs.push_back(unordered_set<const char*>());
    		for(auto it = DPs[cur_levl-1].begin(); it != DPs[cur_levl-1].end(); it++){
    			string tmp = *it;
    			for(int i=tmp.length()-1; i>=0; --i){
    				char back = tmp[i];
    				for(tmp[i] = 'a'; tmp[i] <= 'z'; ++tmp[i]){
    					auto ret = dict.find(tmp);
    					if(ret != dict.end() && added.count(ret->c_str()) == 0){
    						DPs[cur_levl].insert(ret->c_str());
    						added.insert(ret->c_str());
    					}
    				}
    				tmp[i] = back;
    			}
    		}
    	}
    }

    inline int _distance(const string& l, const string& r){
        int distance = 0;
    	const char* l_s = l.c_str();
    	const char* l_r = r.c_str();
    	for(int i=l.size()-1; i>=0; --i){
    		distance+= l_r[i] == l_s[i] ? 0 : 1;
    	}
    	return distance;
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<unordered_set<const char*>> DPs_form_start;
    	vector<unordered_set<const char*>> DPs_form_end;
    	get_ladder_dp(dict.find(start)->c_str(), dict.find(end)->c_str(), dict, DPs_form_start);
        //提前处理没有路径的
        int step = DPs_form_start.size();
        if(DPs_form_start[step-1].empty()){
            return vector<vector<string>>();
        }
        
    	get_ladder_dp(dict.find(end)->c_str(), dict.find(start)->c_str(), dict, DPs_form_end);
        //取交集
    	for(int i=0; i < step; ++i){
    		int j = step - i - 1;
    		for(auto it=DPs_form_start[i].begin(); it != DPs_form_start[i].end(); ++it){
    			if(DPs_form_end[j].count(*it) ==0){
    				DPs_form_start[i].erase(it);
    				it = DPs_form_start[i].begin();
    			}
    		}
    	}
        //合并答案
    	vector<vector<string>> result(1,vector<string>(1,start)), tmp;
    	for(int levl = 1; levl < DPs_form_start.size(); ++levl){
    		for (int i = result.size()-1; i>=0; --i)	{
    			string cur = result[i][result[i].size()-1];
    			for (auto it = DPs_form_start[levl].begin(); it !=DPs_form_start[levl].end(); ++it){
    				if(_distance(cur, *it) == 1){
    					tmp.push_back(result[i]);
    					tmp.back().push_back(*it);
    				}
    			}
    		}
    		swap(result, tmp);
    		tmp.clear();
    	}
        return result;
    }
};

