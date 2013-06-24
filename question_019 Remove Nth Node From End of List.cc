//添加额外一个节点版
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode pre_head(-1);
        pre_head.next = head;
        ListNode* cur = &pre_head; 
        ListNode* pre_tag = cur;
        for(int i=0;i<n;i++){
            cur = cur->next;
        }
        while(cur->next != NULL){
            pre_tag = pre_tag->next;
            cur = cur->next;
        }
        pre_tag->next = pre_tag->next->next;
        return pre_head.next;
    }
    
    
//不添加额外节点版
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* cur = head; 
        ListNode* pre_tag = cur;
        for(int i=0;i<n;i++){
            cur = cur->next;
        }
        if(cur == NULL)
            return head->next;
        while(cur->next != NULL){
            pre_tag = pre_tag->next;
            cur = cur->next;
        }
        pre_tag->next = pre_tag->next->next;
        return head;
    }