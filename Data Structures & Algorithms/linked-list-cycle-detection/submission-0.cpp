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
    bool hasCycle(ListNode* head) {
        ListNode* fp = head;
        ListNode* sp = head;

        while (fp != nullptr) {
            ListNode* t = fp->next;
            if (t && t->next) {
                fp = t->next;
            } else {
                fp = t;
            }
            if (fp == sp) {
                return true;
            }
            sp = sp->next;
        }

        return false;
    }
};
