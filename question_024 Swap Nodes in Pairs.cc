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
    ListNode* reverse(ListNode* pre, ListNode* last){
        ListNode* begin = pre->next;
        ListNode* end = begin->next;
        while(end != last){
            begin->next = end->next;
            end->next = pre->next;
            pre->next = end;
            end = begin->next;
        }
        return begin;
    }

    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* pre = &dummyNode;
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL){
            pre = reverse(pre, cur->next->next);
            cur = pre->next;
        }
        return dummyNode.next;
    }
};