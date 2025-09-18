#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

class Library {
    vector<Book> books;

    public:
        void addBook(int id, string title, string author) {
            Book newBook(id, title, author);
            books.push_back(newBook);
            cout << "Book addaed successfully!\n";
        }

        void displayBooks() {
            cout << "\n Library BBoks:\n";
            if (books.empty()){
                cout << "No books in Library. \n";
                return;
            }
            for(auto &b : books){
                cout << "ID: " << b.id
                     << " | Title : " << b.title
                     << " | Author : " << b.author
                     << " | Status : " << (b.isIssued ? "Issued" : "Available")
                     << endl;
            }
        }

        void searchBook(int id) {
            for(auto &b : books) {
                if (b.id == id) {
                    cout << " Found: " << b.title << " by " << b.author
                         << " (" << (b.isIssued ? "Issued" : "Available") << ")\n";
                         return;
                }
            }
            cout << "Book not found! \n";
        }

        void issuedBook(int id){
            for(auto &b : books) {
                if (b.id == id) {
                    if(b.isIssued) {
                        cout << " Book already issued! \n";
                    }else{
                        b.isIssued = true;
                        cout << "Book issued successfully! \n";
                    }
                    return;
                }
            }
            cout << "Book not found! \n";
        }

        void returnBook(int id) {
            for( auto &b : books) {
                if(b.id == id) {
                    if(!b.isIssued) {
                        cout << "Book was not issued!\n";
                    }else{
                        b.isIssued = false;
                        cout << " Book  return successfully!\n";
                    }
                    return;
                }
            }
            cout << "Book not found!\n";
        }

};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    while(true) {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Book\n";
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
                getline(cin , title);
                cout << "Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;

            case 2:
                lib.displayBooks();
                break;
            
            case 3:
                cout << "enter Book ID: ";
                cin >> id;                
                lib.searchBook(id);
                break;

            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issuedBook(id);
                break;

            case 5:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                cout << "Exiting Library Syatem. Goodbye! \n";
                return 0;

            default:
                cout << "Invalid choice, please tey again. \n";
        }
    }
}