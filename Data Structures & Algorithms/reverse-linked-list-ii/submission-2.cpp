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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeLeft = new ListNode();
        ListNode* leftNode = head;  
        beforeLeft->next = leftNode;
        int i = 1;
        while (i < left) {
            beforeLeft = beforeLeft->next;
            leftNode = leftNode->next;
            i++;
        }
        ListNode* prev = leftNode;
        ListNode* nextNode = prev->next;
        prev->next = nullptr;
        while (i < right) {
            ListNode* temp = nextNode->next;
            nextNode->next = prev;
            prev = nextNode;
            nextNode = temp;
            i++;
        }
        leftNode->next = nextNode;
        beforeLeft->next = prev;

        if (left == 1) {
            return beforeLeft->next;
        }

        return head;
    }
};