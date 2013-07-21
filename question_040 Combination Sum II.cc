class Solution {
public:
    set<vector<int> > result;
    vector<int> path;
    void combine(vector<int>::iterator begin, vector<int>::iterator end, int target){
        if(begin == end || *begin > target)
            return;
        
        path.push_back(*begin);
        if(target-*begin == 0)
            result.insert(path);
        else
            combine(begin+1, end, target-*begin);
        path.pop_back();
        combine(begin+1, end, target);
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        path.clear();
        result.clear();
        combine(candidates.begin(), candidates.end(), target);
        return vector<vector<int>>(result.begin(), result.end());
    }
};