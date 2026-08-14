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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before = new ListNode();
        before->next = head;
        ListNode* after = head;
        ListNode* t = head;
        while(t) {
            n--;
            if (n == 0) {
                after = after->next;
            } else if (n < 0) {
                after = after->next;
                before = before->next;
            }
            t = t->next;
        }

        if (after == head) {
            return nullptr;
        }

        if (before->next == head) {
            return after;
        }

        before->next = after;
        return head;
    }
};
