class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *g_head = NULL;
        ListNode *s_head = NULL;
        ListNode *g_pos = NULL;
        ListNode *s_pos = NULL;
        while(head != NULL){
            if(head->val >= x){
                if(g_head == NULL){
                    g_head = head;
                    g_pos = g_head;
                }else{
                    g_pos->next = head;
                    g_pos = g_pos->next;
                }
            }else{
                if(s_head == NULL){
                    s_head = head;
                    s_pos = s_head;
                }else{
                    s_pos->next = head;
                    s_pos = s_pos->next;
                }
            }
            head = head->next;    
        }
        if(s_pos != NULL)
                s_pos->next = g_head;
        if(g_pos != NULL)
            g_pos->next = NULL;
        if(s_head != NULL)
            return s_head;
        else
            return g_head;
    }
}; 