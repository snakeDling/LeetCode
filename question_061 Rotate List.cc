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
    
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* pre = &dummyNode;
        int count = 0;
        while(head != NULL){
            ++count;
            head = head->next;
        }
        k = k%count;
        head = pre->next;
        for(int i=0; i<count-k; ++i){
            head = head->next;
        }
        ListNode *next = pre->next;
        if(k!=0){
            reverse(pre, head);
            reverse(next, NULL);
            reverse(pre, NULL);
        }
        return pre->next;
    }
};