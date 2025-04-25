#include <iostream>
using namespace std;

class HashTableEntry {
public:
    int k; // Key
    int v; // Value

    HashTableEntry(int k, int v) : k(k), v(v) {}
};

class HashMapTable {
	public:
    static const int TABLE_SIZE = 10; // Adjust size as needed
    HashTableEntry **t;

    // Constructor
    HashMapTable() {
        t = new HashTableEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i) {
            t[i] = nullptr;
        }
    }

    // Hash function
    int HashFunc(int k) {
        return k % TABLE_SIZE;
    }

    // Insert key-value pair
    void Insert(int k, int v) {
        int hash = HashFunc(k);
        if (t[hash] == nullptr) {
            t[hash] = new HashTableEntry(k, v);
        } else {
            // Handle collisions (for now, replace value if key exists)
            if (t[hash]->k == k) {
                t[hash]->v = v; // Update value
            } else {
                cout << "Collision occurred. Implement a resolution strategy.\n";
            }
        }
    }

    // Search for a key
    int SearchKey(int k) {
        int hash = HashFunc(k);
        if (t[hash] != nullptr && t[hash]->k == k) {
            return t[hash]->v;
        } else {
            return -1; // Indicate not found
        }
    }

    // Remove a key-value pair
    void Remove(int k) {
        int hash = HashFunc(k);
        if (t[hash] != nullptr && t[hash]->k == k) {
            delete t[hash];
            t[hash] = nullptr;
        } else {
            cout << "Key not found.\n";
        }
    }

    // Destructor
    ~HashMapTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            delete t[i];
        }
        delete[] t;
    }
};

int main() {
    HashMapTable ht;

    ht.Insert(1, 10);
    ht.Insert(2, 20);
    ht.Insert(11, 30); // This will cause a collision

    cout << "Value for key 1: " << ht.SearchKey(1) << endl;
    cout << "Value for key 2: " << ht.SearchKey(2) << endl;
    cout << "Value for key 11: " << ht.SearchKey(11) << endl;

    ht.Remove(1);
    cout << "Value for key 1 after removal: " << ht.SearchKey(1) << endl;

    return 0;
}
