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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } if (!list2) {
            return list1;
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        if (t1->val <= t2->val) {
            head = t1;
            curr = t1;
            t1 = t1->next;
        } else {
            head = t2;
            curr = t2;
            t2 = t2->next;
        }
        while (t1 && t2) {
            if (t1->val <= t2->val) {
                curr->next = t1;
                curr = t1;
                t1 = t1->next;
            } else {
                curr->next = t2;
                curr = t2;
                t2 = t2->next;
            }
        }

        while (t1) {
            curr->next = t1;
            curr = t1;
            t1 = t1->next;
        }

        while (t2) {
            curr->next = t2;
            curr = t2;
            t2 = t2->next;
        }

        curr->next = nullptr;
        return head;
    }
};
