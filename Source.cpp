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
private:
    int findIndex(AccessMode mode) const {
        if (data.empty()) {
            return -1;
        }

        int bestIndex = 0;

        for (int i = 1; i < data.size(); i++) {
            switch (mode) {
            case AccessMode::Highest:
                if (data[i].priority > data[bestIndex].priority) {
                    bestIndex = i;
                }
                else if (data[i].priority == data[bestIndex].priority &&
                    data[i].order < data[bestIndex].order) {
                    bestIndex = i;
                }
                break;

            case AccessMode::Lowest:
                if (data[i].priority < data[bestIndex].priority) {
                    bestIndex = i;
                }
                else if (data[i].priority == data[bestIndex].priority &&
                    data[i].order < data[bestIndex].order) {
                    bestIndex = i;
                }
                break;

            case AccessMode::Oldest:
                if (data[i].order < data[bestIndex].order) {
                    bestIndex = i;
                }
                break;

            case AccessMode::Newest:
                if (data[i].order > data[bestIndex].order) {
                    bestIndex = i;
                }
                break;
            }
        }

        return bestIndex;
    }
};
void printEntry(const BiDirectionalPriorityQueue::Entry& entry) {
    cout << "Item: " << entry.item
        << " | Priority: " << entry.priority
        << " | Order: " << entry.order << endl;
}

int main() {
    BiDirectionalPriorityQueue queue;
    int choice;

    do {
        cout << "\n===== BI-DIRECTIONAL PRIORITY QUEUE =====\n";
        cout << "1. Enqueue item\n";
        cout << "2. Dequeue highest priority\n";
        cout << "3. Dequeue lowest priority\n";
        cout << "4. Dequeue oldest item\n";
        cout << "5. Dequeue newest item\n";
        cout << "6. Peek highest priority\n";
        cout << "7. Peek lowest priority\n";
        cout << "8. Peek oldest item\n";
        cout << "9. Peek newest item\n";
        cout << "10. Show all items\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int priority;

            cout << "Enter item: ";
            cin >> item;

            cout << "Enter priority: ";
            cin >> priority;

            queue.enqueue(item, priority);
            cout << "Item added.\n";
        }
        else if (choice == 2) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.dequeue(AccessMode::Highest, result)) {
                cout << "Removed highest priority item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 3) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.dequeue(AccessMode::Lowest, result)) {
                cout << "Removed lowest priority item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 4) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.dequeue(AccessMode::Oldest, result)) {
                cout << "Removed oldest item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 5) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.dequeue(AccessMode::Newest, result)) {
                cout << "Removed newest item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 6) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.peek(AccessMode::Highest, result)) {
                cout << "Highest priority item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 7) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.peek(AccessMode::Lowest, result)) {
                cout << "Lowest priority item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 8) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.peek(AccessMode::Oldest, result)) {
                cout << "Oldest item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 9) {
            BiDirectionalPriorityQueue::Entry result;
            if (queue.peek(AccessMode::Newest, result)) {
                cout << "Newest item:\n";
                printEntry(result);
            }
            else {
                cout << "Queue is empty.\n";
            }
        }
        else if (choice == 10) {
            queue.printAll();
        }
        else if (choice == 0) {
            cout << "Program finished.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

   
