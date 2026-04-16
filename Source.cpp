#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class AccessMode {
    Highest,
    Lowest,
    Oldest,
    Newest
};

class BiDirectionalPriorityQueue {
public:
    struct Entry {
        string item;
        int priority;
        int order;
    };

private:
    vector<Entry> data;
    int nextOrder;

public:
    BiDirectionalPriorityQueue() {
        nextOrder = 0;
    }

    void enqueue(string item, int priority) {
        Entry newEntry;
        newEntry.item = item;
        newEntry.priority = priority;
        newEntry.order = nextOrder++;

        data.push_back(newEntry);
    }

    bool peek(AccessMode mode, Entry& result) const {
        int index = findIndex(mode);

        if (index == -1) {
            return false;
        }

        result = data[index];
        return true;
    }

    bool dequeue(AccessMode mode, Entry& result) {
        int index = findIndex(mode);

        if (index == -1) {
            return false;
        }

        result = data[index];
        data.erase(data.begin() + index);
        return true;
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }

    void printAll() const {
        if (data.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCurrent queue:\n";
        for (int i = 0; i < data.size(); i++) {
            cout << i + 1
                << ". Item: " << data[i].item
                << " | Priority: " << data[i].priority
                << " | Order: " << data[i].order
                << endl;
        }
    }

    return 0;
}