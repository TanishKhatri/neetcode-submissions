class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        if (key < root->key) {
            root->left = insert(root->left, key);
        } else if (key > root->key) {
            root->right = insert(root->right, key);
        } 
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr;
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* curr = root->right;
            while(curr->left) {
                curr = curr->left;
            }
            root->key = curr->key;
            root->right = deleteNode(root->right, curr->key);
        }
        return root;
    }

    bool search(Node* root, int key) {
        if (!root) return false;
        if (key == root->key) return true;
        if (key < root->key) {
            return search(root->left, key);
        } else {
            return search (root->right, key);
        }
    }

    Node* root;

public:
    BST() : root(nullptr) {}

    void add(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool contains(int key) {
        return search(root, key);
    }
};

class MyHashSet {
private:
    const int size = 10000; 
    vector<BST> hashTree;

    int hash(int key) {
        return key % size;
    } 
public:
    MyHashSet() : hashTree(size) {}
    
    void add(int key) {
        hashTree[hash(key)].add(key);
    }
    
    void remove(int key) {
        hashTree[hash(key)].remove(key);
    }
    
    bool contains(int key) {
        return hashTree[hash(key)].contains(key);
    }
};