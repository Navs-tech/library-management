#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// ------------------ Book Class ------------------
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int _id, string _title, string _author) {
        id = _id;
        title = _title;
        author = _author;
        isIssued = false;
    }
};

// ------------------ Library Class ------------------
class Library {
    vector<Book> books;                         // store all books
    unordered_map<int, int> bookIndexById;      // maps book ID -> index in vector

public:
    // Add new book
    void addBook(int id, string title, string author) {
        if (bookIndexById.find(id) != bookIndexById.end()) {
            cout << " Book with ID " << id << " already exists!\n";
            return;
        }
        Book newBook(id, title, author);
        books.push_back(newBook);
        bookIndexById[id] = books.size() - 1;   // store index of this book
        cout << " Book added successfully!\n";
    }

    // Display all books
    void displayBooks() {
        cout << "\nLibrary Books:\n";
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (auto &b : books) {
            cout << "ID: " << b.id
                 << " | Title: " << b.title
                 << " | Author: " << b.author
                 << " | Status: " << (b.isIssued ? "Issued" : "Available")
                 << endl;
        }
    }

    // Search by ID (O(1) lookup)
    void searchBook(int id) {
        if (bookIndexById.find(id) == bookIndexById.end()) {
            cout << " Book not found!\n";
            return;
        }
        Book &b = books[bookIndexById[id]];
        cout << "Found: " << b.title << " by " << b.author
             << " (" << (b.isIssued ? "Issued" : "Available") << ")\n";
    }

    // Issue book (O(1))
    void issueBook(int id) {
        if (bookIndexById.find(id) == bookIndexById.end()) {
            cout << "Book not found!\n";
            return;
        }
        Book &b = books[bookIndexById[id]];
        if (b.isIssued) {
            cout << "Book already issued!\n";
        } else {
            b.isIssued = true;
            cout << "Book issued successfully!\n";
        }
    }

    // Return book (O(1))
    void returnBook(int id) {
        if (bookIndexById.find(id) == bookIndexById.end()) {
            cout << "Book not found!\n";
            return;
        }
        Book &b = books[bookIndexById[id]];
        if (!b.isIssued) {
            cout << "Book was not issued!\n";
        } else {
            b.isIssued = false;
            cout << "Book returned successfully!\n";
        }
    }
};

// ------------------ Main Function ------------------
int main() {
    Library lib;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.searchBook(id);
                break;

            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 5:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                cout << "Exiting Library System. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}
