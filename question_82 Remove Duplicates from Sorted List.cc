/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        ListNode* cur = head;
        while(cur->next != NULL){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};