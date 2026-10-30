#include <iostream>
using namespace std;

// 1. Abstract Queue Class
template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};

// 2. Child Class myQueue
template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int count;
    int frontIndex;
    int rearIndex;

public:

    // Constructor
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        count = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    // Insert element
    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        cout << value << " inserted successfully!" << endl;
    }

    // Remove element
    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return value;
    }

    // Get front element
    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return arr[frontIndex];
    }

    // Check empty
    bool isEmpty() const override {
        return count == 0;
    }

    // Check full
    bool isFull() const override {
        return count == capacity;
    }

    // Display queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements (Front to Rear): ";

        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~myQueue() {
        delete[] arr;
    }
};

// 3. Main Function
int main() {

    int size;
    cout << "Enter Queue Size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    myQueue<int> q(size);

    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. EnQueue (Insert)" << endl;
        cout << "2. DeQueue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed Element: " << q.deQueue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is Not Full." << endl;
            break;

        case 7:
            cout << "Program Exited!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}