//这题坑好多，要实现成最有效率的方式，代码会好长，没有耐心了，然后觉得这种实现速度还能接受，就这么搞了。代码相对比较简洁。
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode head(-1);
        ListNode* end = &head;
        while(!lists.empty()){
            while(!lists.empty() && lists[lists.size()-1] == NULL){
                lists.pop_back();
            }
            int idx = lists.size()-1;
            for(int i=lists.size()-2; i>=0; --i){
                if(lists[i] != NULL && lists[idx]->val > lists[i]->val){
                    idx=i;
                }
            }
            if(!lists.empty()){
                end = end->next = lists[idx];
                lists[idx] = lists[idx]->next;
            }
        }
        return head.next;
    }