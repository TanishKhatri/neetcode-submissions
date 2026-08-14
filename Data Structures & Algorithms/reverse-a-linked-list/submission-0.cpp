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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* lastNode = head;
        ListNode* curr = lastNode->next;
        head->next = nullptr;
        while (curr != nullptr) {
            ListNode*  t = curr->next;
            curr->next = lastNode;
            lastNode = curr;
            curr = t;
        }
        return lastNode;
    }
};
