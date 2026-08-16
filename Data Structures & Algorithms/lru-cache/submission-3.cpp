struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int size = 0;
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        Node* temp = it->second;
        if (temp == tail) {
            return temp->value;
        }

        if (temp == head) {
            head = temp->next;
            temp->next->prev = nullptr;
            temp->next = nullptr;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        } else {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        return temp->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* temp = it->second;
            temp->value = value;
            if (temp == tail) {
                return;
            }

            if (temp == head) {
                head = temp->next;
                temp->next->prev = nullptr;
                temp->next = nullptr;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            } else {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            } 
        } else {
            if (size >= capacity) {
                Node* temp = head;
                if (size == 1) {
                    head = nullptr;
                    tail = nullptr;
                    cache.erase(temp->key);
                    delete temp;
                    size--;
                } else {
                    head = temp->next;
                    head->prev = nullptr;
                    cache.erase(temp->key);
                    delete temp;
                    size--;
                }
            }
            if (!head) {
                Node* temp = new Node(key, value);
                head = temp;
                tail = temp;
                cache[key] = temp;
                size++;
            } else {
                Node* temp = new Node(key, value);
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                cache[key] = temp;
                size++;
            }
        }
    }
};
