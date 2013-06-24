///////////////////堆栈版
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode doMeNode(0);
        ListNode* pre = & doMeNode;
        pre->next = head;
        ListNode* cur = head;
        stack<ListNode*> s;
        while(true){
            for(int i=k; i>0; --i){
                if(cur == NULL)
                    return doMeNode.next;
                s.push(cur);
                cur = cur->next;
            }
            while(!s.empty()){
                pre = pre->next = s.top();
                s.pop();
            }
            pre->next = cur;
        }
    }
};


////////////////链表直接转换版
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode doMeNode(0);
        ListNode* pre = & doMeNode;
        pre->next = head;
        ListNode* next = head, *last = NULL, *cur = NULL;
        while(true){
            for(int i=k; i>0; --i){
                if(next == NULL)
                    return doMeNode.next;
                next = next->next;
            }
            last = pre->next;
            cur = last->next;
            while(cur != next){
                last->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
                
                cur = last->next;
            }
            pre = last;
            
        }
    }
};