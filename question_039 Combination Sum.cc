class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    void combine(vector<int>::iterator begin, vector<int>::iterator end, int target){
        if(begin == end || *begin > target)
            return;
        
        int count = 0, back=target;
        while((target-=*begin)>=0){
            path.push_back(*begin);
            if(target == 0)
                result.push_back(path);
            else
                combine(begin+1, end, target);
            count++;
        }
        for(;count>0; --count){
            path.pop_back();
        }
        combine(begin+1, end, back);
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        path.clear();
        result.clear();
        combine(candidates.begin(), candidates.end(), target);
        return result;
    }
};