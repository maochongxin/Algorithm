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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        ListNode* t = new ListNode(l1->val + l2->val);
        
        l1 = l1->next;
        l2 = l2->next;
        ListNode* p = t;
        if(p->val >= 10) {
            p->val %= 10;
            p->next = new ListNode(1);
        }
        while(l1 != NULL && l2 != NULL) {
            if(p->next != NULL) {
                p->next->val += l1->val + l2->val;
                if(p->next->val >= 10) {
                    p->next->val %= 10;
                    p->next->next = new ListNode(1);
                }
                l1 = l1->next;
                l2 = l2->next;
                p = p->next;
            } else {
                p->next = new ListNode(l1->val + l2->val);
                if(p->next->val >= 10) {
                    p->next->val %= 10;
                    p->next->next = new ListNode(1);
                }
                l1 = l1->next;
                l2 = l2->next;
                p = p->next;
            }
        }
        if(l1 == NULL) {
            while(l2 != NULL) {
                if(p->next != NULL) {
                    p->next->val += l2->val;
                } else {
                    p->next = new ListNode(l2->val);
                }
                if (p->next->val >= 10) {
                    p->next->val %= 10;
                    p->next->next = new ListNode(1);
                }
                l2 = l2->next;
                p = p->next;
            }
        } else if(l2 == NULL) {
            while(l1 != NULL) {
                if(p->next != NULL) {
                    p->next->val += l1->val;
                } else {
                    p->next = new ListNode(l1->val);
                }
                if (p->next->val >= 10) {
                    p->next->val %= 10;
                    p->next->next = new ListNode(1);
                }
                l1 = l1->next;
                p = p->next;
            }
        }
        return t;
    }
};
