#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Book {
    string title;
    int quantity;
    int priority;

    // Constructor
    Book(string _title, int _quantity, int _priority) : title(_title), quantity(_quantity), priority(_priority) {}

    // Operator overload for comparison
    bool operator<(const Book& other) const {
        return priority > other.priority; // Higher priority has lower value
    }
};

int main() {
    priority_queue<Book> inventory;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title;
            int quantity, priority;

            cin.ignore(); // Clear newline left in the input buffer
            getline(cin, title);
            cin >> quantity;
            cin >> priority;

            if (priority < 1 || priority > 5) {
                cout << "Invalid restock priority. Please enter a value between 1 and 5.\n";
            } else {
                Book newBook(title, quantity, priority);
                inventory.push(newBook);
                cout << "Book added to the inventory.\n";
            }
        } else if (choice == 2) {
            if (!inventory.empty()) {
                Book restockedBook = inventory.top();
                inventory.pop();
                cout << "Restocked book: " << restockedBook.title << endl;
            } else {
                cout << "No books in the inventory.\n";
            }
        } else if (choice == 3) {
            if (!inventory.empty()) {
                Book nextBookToRestock = inventory.top();
                cout << "Next book to restock: " << nextBookToRestock.title << endl;
            } else {
                cout << "No books in the inventory.\n";
            }
        } else if (choice == 4) {
            cout << "Exiting the application.\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
