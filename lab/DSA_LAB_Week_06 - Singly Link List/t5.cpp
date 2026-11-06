
#include <iostream>
#include <string>
using namespace std;

// Student Node
class StudentNode {
public:
    string studentName;
    int priority;
    StudentNode* next;

    StudentNode(string name, int p) {
        studentName = name;
        priority = p;
        next = nullptr;
    }
};

// Book Node
class BookNode {
public:
    string bookName;
    StudentNode* studentHead;
    BookNode* next;

    BookNode(string name) {
        bookName = name;
        studentHead = nullptr;
        next = nullptr;
    }
};

// Library ADT
class Library {
private:
    BookNode* head;

    // Find a book
    BookNode* findBook(string name) {
        BookNode* temp = head;

        while (temp != nullptr) {
            if (temp->bookName == name) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    // Insert student according to priority
    void insertByPriority(BookNode* book,
        string name, int priority) {

        StudentNode* newNode =
            new StudentNode(name, priority);

        // Insert at beginning
        if (book->studentHead == nullptr ||
            priority < book->studentHead->priority) {

            newNode->next = book->studentHead;
            book->studentHead = newNode;
            return;
        }

        StudentNode* temp = book->studentHead;

        // Maintain arrival order for equal priorities
        while (temp->next != nullptr &&
            temp->next->priority <= priority) {

            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

public:

    // Constructor
    Library() {
        head = nullptr;
    }

    // Add a new book
    void addBook(string name) {

        if (findBook(name) != nullptr) {
            cout << "Book already exists!" << endl;
            return;
        }

        BookNode* newBook = new BookNode(name);

        newBook->next = head;
        head = newBook;

        cout << "Book added successfully!" << endl;
    }

    // 1. Add Student Reservation
    void addStudent(string bookName,
        string studentName,
        int priority = 3) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        if (priority < 1 || priority > 3) {
            cout << "Invalid priority!" << endl;
            return;
        }

        insertByPriority(book, studentName, priority);

        cout << studentName
            << " added to reservation list!" << endl;
    }

    // 2. Remove Student Reservation
    void removeStudent(string bookName,
        string studentName) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        StudentNode* temp = book->studentHead;

        if (temp == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        // Remove first student
        if (temp->studentName == studentName) {
            book->studentHead = temp->next;
            delete temp;

            cout << "Reservation cancelled!" << endl;
            return;
        }

        // Search student
        while (temp->next != nullptr &&
            temp->next->studentName != studentName) {

            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found!" << endl;
        }
        else {
            StudentNode* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Reservation cancelled!" << endl;
        }
    }

    // 3. Update Student Priority
    void updatePriority(string bookName,
        string studentName,
        int newPriority) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority!" << endl;
            return;
        }

        StudentNode* temp = book->studentHead;

        // Search student
        while (temp != nullptr &&
            temp->studentName != studentName) {

            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        if (temp->priority == newPriority) {
            cout << "Priority is already the same!" << endl;
            return;
        }

        // Remove student from old position
        removeStudent(bookName, studentName);

        // Insert student according to new priority
        insertByPriority(book, studentName, newPriority);

        cout << "Priority updated successfully!" << endl;
    }

    // 4. Display Reservation List
    void displayQueue(string bookName) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        StudentNode* temp = book->studentHead;

        cout << "\nReservation List: "
            << book->bookName << endl;

        if (temp == nullptr) {
            cout << "No reservations!" << endl;
            return;
        }

        while (temp != nullptr) {

            cout << "Student: " << temp->studentName;

            cout << " | Priority: ";

            if (temp->priority == 1)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << endl;

            temp = temp->next;
        }
    }

    // 5. Count Students
    void countStudents(string bookName) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        int count = 0;

        StudentNode* temp = book->studentHead;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total reservations for "
            << bookName << ": " << count << endl;
    }

    // 6. Return Book - Serve First Student
    void returnBook(string bookName) {

        BookNode* book = findBook(bookName);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
            return;
        }

        if (book->studentHead == nullptr) {
            cout << "No student waiting for this book!" << endl;
            return;
        }

        StudentNode* temp = book->studentHead;

        cout << "Book returned! Now serving: "
            << temp->studentName << endl;

        book->studentHead = book->studentHead->next;

        delete temp;
    }

    // Destructor
    ~Library() {

        while (head != nullptr) {

            BookNode* book = head;
            head = head->next;

            while (book->studentHead != nullptr) {

                StudentNode* temp = book->studentHead;

                book->studentHead =
                    book->studentHead->next;

                delete temp;
            }

            delete book;
        }
    }
};

// Main Function
int main() {

    Library library;

    // Add Books
    library.addBook("Data Structures");
    library.addBook("Operating Systems");

    // Add Students to Data Structures
    cout << "\nAdding Students to Data Structures:\n";

    library.addStudent("Data Structures", "Ali", 3);
    library.addStudent("Data Structures", "Ahmed", 2);
    library.addStudent("Data Structures", "Sara", 1);
    library.addStudent("Data Structures", "Ayesha", 2);

    // Add Students to Operating Systems
    cout << "\nAdding Students to Operating Systems:\n";

    library.addStudent("Operating Systems", "Usman", 3);
    library.addStudent("Operating Systems", "Hina", 1);
    library.addStudent("Operating Systems", "Zain", 2);

    // Display Both Queues
    library.displayQueue("Data Structures");
    library.displayQueue("Operating Systems");

    // Update Priority
    cout << "\nUpdating Priority:\n";

    library.updatePriority(
        "Data Structures", "Ali", 1
    );

    library.displayQueue("Data Structures");

    // Cancel Reservation
    cout << "\nCancelling Reservation:\n";

    library.removeStudent(
        "Operating Systems", "Zain"
    );

    library.displayQueue("Operating Systems");

    // Count Students
    cout << "\nCounting Reservations:\n";

    library.countStudents("Data Structures");
    library.countStudents("Operating Systems");

    // Return Book
    cout << "\nReturning Book:\n";

    library.returnBook("Data Structures");

    library.displayQueue("Data Structures");

    return 0;
}
