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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* p = head;
        ListNode* newHead = head;
        while (head->next) {
            p = head->next;
            head->next = p->next;
            p->next = newHead;
            newHead = p;
        }
        return newHead;
    }
};
