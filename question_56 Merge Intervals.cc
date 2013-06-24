/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    inline bool canMerge(Interval &l, Interval &r){
        return l.end >= r.start;
    }
    
    inline void merge(Interval &dest, Interval &append){
        dest.start = min(dest.start, append.start);
        dest.end = max(dest.end, append.end);
    }
    
    static bool LessThan(const Interval &l, const Interval &r){
        return l.start < r.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), LessThan);
        vector<Interval> result(1, intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            if(canMerge(result.back(), intervals[i])){
                merge(result.back(), intervals[i]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};