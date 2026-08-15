struct Node {
    int value;
    Node* prev;
    Node* next;
    Node() : value(0), next(nullptr), prev(nullptr) {}
    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

class MyCircularQueue {
private:
    int size;
    int capacity;
    Node* rear = nullptr;
    Node* front = nullptr;
public:
    MyCircularQueue(int k) : size(0), capacity(k) {}
    
    bool enQueue(int value) {
        if (size >= capacity) return false;
        if (!rear && !front) {
            Node* temp = new Node(value);
            temp->next = temp;
            temp->prev = temp;
            rear = temp;
            front = temp;
            size++;
            return true;
        }

        Node* temp = new Node(value);
        temp->next = rear;
        rear->prev = temp;
        temp->prev = front;
        rear = temp;
        front->next = rear;
        size++;
        return true;    
    }
    
    bool deQueue() {
        if (size <= 0) return false;
        if (size == 1) {
            front = nullptr;
            rear = nullptr;
            size--;
            return true;
        }
        front = front->prev;
        front->next = rear;
        rear->prev = front;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        return front->value;
    }
    
    int Rear() {
        if (size == 0) return -1;
        return rear->value;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */