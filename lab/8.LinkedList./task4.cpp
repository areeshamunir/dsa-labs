
#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int x;
    int y;
    Node* next;
};

// Add New Head
void addHead(Node*& head, int x, int y) {

    Node* newNode = new Node();

    newNode->x = x;
    newNode->y = y;

    newNode->next = head;
    head = newNode;
}

// Grow Snake
void grow(Node*& head, int x, int y) {

    addHead(head, x, y);

    cout << "Snake grew! New head added.\n";
}

// Collision Detection
bool collisionCheck(Node* head, int x, int y,
    bool ignoreTail) {

    if (head == nullptr)
        return false;

    Node* tail = head;

    // Find tail if it will be removed
    if (ignoreTail) {
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }

    // Check existing body segments
    while (head != nullptr) {

        // Ignore old tail during normal movement
        if (ignoreTail && head == tail) {
            head = head->next;
            continue;
        }

        if (head->x == x && head->y == y) {
            return true;
        }

        head = head->next;
    }

    return false;
}

// Remove Tail
void removeTail(Node*& head) {

    if (head == nullptr)
        return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Movement Function
bool move(Node*& head, int x, int y, bool ateFood) {

    // Check collision
    if (collisionCheck(head, x, y, !ateFood)) {

        cout << "COLLISION DETECTED!\n";
        cout << "Snake cannot move to ("
            << x << ", " << y << ")\n";

        return false;
    }

    // Add new head
    addHead(head, x, y);

    if (ateFood) {

        cout << "Food eaten! Snake length increased.\n";

    }
    else {

        removeTail(head);

        cout << "Snake moved successfully.\n";
    }

    return true;
}

// Print Snake
void printSnake(Node* head) {

    cout << "Snake: ";

    while (head != nullptr) {

        cout << "(" << head->x
            << "," << head->y << ")";

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << " -> NULL\n";
}

// Free Memory
void clearSnake(Node*& head) {

    while (head != nullptr) {

        Node* temp = head;
        head = head->next;

        delete temp;
    }
}

// Main Function
int main() {

    Node* snake = nullptr;

    // Initial Snake
    addHead(snake, 0, 0);
    addHead(snake, 1, 0);
    addHead(snake, 2, 0);

    cout << "Initial Snake:\n";
    printSnake(snake);

    // Move 1: Normal Movement
    cout << "\nMove 1:\n";

    move(snake, 3, 0, false);
    printSnake(snake);

    // Move 2: Eat Food
    cout << "\nMove 2:\n";

    move(snake, 4, 0, true);
    printSnake(snake);

    // Move 3: Self Collision
    cout << "\nMove 3:\n";

    move(snake, 3, 0, false);
    printSnake(snake);

    clearSnake(snake);

    return 0;
}
