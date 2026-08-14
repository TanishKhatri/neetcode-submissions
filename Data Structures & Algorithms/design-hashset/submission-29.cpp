class MyHashSet {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k) : key(k), next(nullptr) {};
    };

    vector<Node*> table = vector<Node*>(10000, nullptr);

public:

    int hash(int key) {
        return key % 10000;
    }

    void add(int key) {
        int hashKey = hash(key);
        if (table[hashKey] == nullptr) {
            Node* curr = new Node(key);
            table[hashKey] = curr; 
        } else {
            Node* curr = table[hashKey];
            while (curr->next != nullptr) {
                if (curr->key == key) {
                    return;
                }
                curr = curr->next; 
            }
            curr->next = new Node(key);
        }
    }

    void remove(int key) {
        int hashKey = hash(key);
        if (table[hashKey] == nullptr) {
            return;
        }
        Node* curr = table[hashKey];
        if (curr->key == key) {
            table[hashKey] = nullptr;
            return;
        }
        while(curr->next != nullptr) {
            if (curr->next->key == key) {
                curr->next = curr->next->next;
            }
        }

    }

    bool contains(int key) {
        int hashKey = hash(key);
        if (table[hashKey] == nullptr) {
            return false;
        }

        Node* curr = table[hashKey];
        while(curr != nullptr) {
            if (curr->key == key) {
                return true;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */