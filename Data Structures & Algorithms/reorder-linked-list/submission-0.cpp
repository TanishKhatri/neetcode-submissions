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
    void reorderList(ListNode* head) {
        ListNode* l = head;
        ListNode* c = head;
        ListNode* r = head;
        while (r->next) {
            r = r->next;
        }
        while (l != r) {
            ListNode* t = l->next;
            l->next = r;
            r->next = t;
            l = t;
            c = l;
            while (c->next != r) {
                c = c->next;
            }
            r = c;
        }
        l->next = nullptr;
    }
};
