/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        vector<Node*> ogRandom(100, nullptr);
        unordered_map<Node*, int> ogIndexes;
        Node* t = head;
        int n = 0;
        while (t) {
            ogIndexes[t] = n;
            ogRandom[n] = t->random;
            n++;
            t = t->next;
        }
        //for nullptr;
        ogIndexes[t] = n;
        // index i points to index ogIndexes[ogRandom[i]]
        // vector<int> indexToIndex;
        // for (int i = 0; i < n; i++) {
        //     indexToIndex.push_back(ogIndexes[ogRandom[i]]);
        // }

        vector<Node*> newListIndexes;
        t = head;
        Node* newHead = new Node(head->val);
        Node* prev = newHead;
        newListIndexes.push_back(newHead);
        t = t->next;
        while (t) {
            Node* node = new Node(t->val);
            newListIndexes.push_back(node);
            prev->next = node;
            prev = prev->next;
            t = t->next;
        }
        newListIndexes.push_back(nullptr);
        for (int i = 0; i < n; i++) {
            newListIndexes[i]->random = newListIndexes[ogIndexes[ogRandom[i]]];
        }

        return newHead;
    }
};
