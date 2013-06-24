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
        ListNode doMeNode(0);
        ListNode* pre = &doMeNode;
        ListNode* cur=head, next = NULL;
        while(cur != NULL){
            if(cur->next != NULL && cur->next->val == cur->val){
                do{
                    cur = cur->next;
                }while(cur->next != NULL && cur->next->val == cur->val);
                cur = cur->next;
            }else{
                pre = pre->next = cur;
                cur = cur->next;
                pre->next = NULL;
            }
        }
        return doMeNode.next;
    }
};