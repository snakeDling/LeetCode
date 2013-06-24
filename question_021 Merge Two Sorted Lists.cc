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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummyNode(0);
        ListNode *head = &dummyNode;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                head = head->next = l1;
                l1 = l1->next;
            }else{
                head = head->next = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL){
            head->next = l1;
        }else{
            head->next = l2;
        }
        return dummyNode.next;
    }
};