//并查集解法，数据量不够大，没有比nlogn的排序后查找快……
class Solution {
public:
    unordered_map<int, int> range_map;
    
    int find_neighbor(int neighbor, int new_belong, int value_array[], int belong_array[]){
        int next = belong_array[neighbor];
        belong_array[neighbor] = new_belong;
        if(next == -1){
            return value_array[neighbor];
        }else{
            return find_neighbor(next, new_belong, value_array, belong_array);
        }
    } 
    
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int value_array[num.size()];
        int belong_array[num.size()];
        range_map.clear();
        int max_len = 0;
        for(int i=num.size()-1; i>=0; --i){
            if(range_map.find(num[i]) != range_map.end()) 
                continue;
            range_map[num[i]] = i;
            value_array[i] = 1;
            belong_array[i] = -1;
            if(range_map.find(num[i]+1) != range_map.end()){
                value_array[i] += find_neighbor(range_map[num[i]+1], i, value_array, belong_array);
            }
            if(range_map.find(num[i]-1) != range_map.end()){
                value_array[i] += find_neighbor(range_map[num[i]-1], i, value_array, belong_array);
            }
            max_len = max(max_len, value_array[i]);
        }
        return max_len;
    }
};