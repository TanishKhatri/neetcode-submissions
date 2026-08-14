/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* toFirstNode = new ListNode();
        ListNode* prev = new ListNode();
        toFirstNode->next = prev;
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int s = t1->val + t2->val + carry;
        prev->val = s % 10;
        carry = s / 10;
        t1 = t1->next;
        t2 = t2->next;
        while (t1 && t2) {
            int s = t1->val + t2->val + carry;
            ListNode* node = new ListNode(s % 10);
            carry = s/10;
            t1 = t1->next;
            t2 = t2->next;
            prev->next = node;
            prev = prev->next;
        }

        while (t1) {
            int s = t1->val + carry;
            ListNode* node = new ListNode(s % 10);
            carry = s/10;
            t1 = t1->next;
            prev->next = node;
            prev = prev->next;
        }

        while (t2) {
            int s = t2->val + carry;
            ListNode* node = new ListNode(s % 10);
            carry = s/10;
            t2 = t2->next;
            prev->next = node;
            prev = prev->next;
        }

        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
            prev = prev->next;
        }

        return toFirstNode->next;
    }
};
