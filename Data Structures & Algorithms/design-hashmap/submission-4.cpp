class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v) {}
    };
    vector<Node*> hashMap;
    int hash(int key) {
        return key % 10000;
    }

public:
    MyHashMap() : hashMap(10000, nullptr) {}
    
    void put(int key, int value) {
        int hashValue = hash(key);
        if (!hashMap[hashValue]) {
            hashMap[hashValue] = new Node(key, value);
            return;
        }

        Node* curr = hashMap[hashValue];
        while (curr->next) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr->next = new Node(key, value);
    }
    
    int get(int key) {
        int hashValue = hash(key);
        if (!hashMap[hashValue]) {
            return -1;
        }
        Node* curr = hashMap[hashValue];
        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = hash(key);
        if (!hashMap[hashValue]) {
            return;
        }
        Node* curr = hashMap[hashValue];
        if (curr->key == key) {
            hashMap[hashValue] = nullptr;
            return;
        }
        while (curr->next) {
            if (curr->next->key == key) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */