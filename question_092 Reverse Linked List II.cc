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
    void reverse(ListNode* pre, ListNode* end){
        if(pre == NULL || pre->next == NULL)
            return;
        ListNode *last = pre->next, *moving = last->next;
        while(moving != end){
            last->next = moving->next;
            moving->next = pre->next;
            pre->next = moving;
            moving = last->next;
        }
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == n)
            return head;
        ListNode dummyNode(0);
        ListNode *pre = &dummyNode;
        pre->next = head;
        for(int i=1; i<m; ++i){
            pre = pre->next;
        }
        head = pre->next;
        for(int i=m; i<=n; ++i){
            head = head->next;
        }
        reverse(pre, head);
        return dummyNode.next;
    }
};