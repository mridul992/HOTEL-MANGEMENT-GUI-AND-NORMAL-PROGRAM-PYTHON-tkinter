#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a Book class
class Book {
private:
    string bookName;
    string authorName;
    int bookID;
    bool status; // 1 for available, 0 for not available

public:
    // Constructor
    Book(string name, string author, int ID) {
        bookName = name;
        authorName = author;
        bookID = ID;
        status = true; // initially, all books are available
    }

    // Getter methods
    string getName() { return bookName; }
    string getAuthor() { return authorName; }
    int getID() { return bookID; }
    bool getStatus() { return status; }

    // Setter methods
    void setStatus(bool newStatus) { status = newStatus; }
};

// Define a Library class
class Library {
private:
    vector<Book> books;

public:
    // Add a book to the library
    void addBook(string name, string author, int ID) {
        Book newBook(name, author, ID);
        books.push_back(newBook);
    }

    // Display all books in the library
    void displayAllBooks() {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << books[i].getName() << " by " << books[i].getAuthor() << ", ID: " << books[i].getID() << ", Status: ";
            if (books[i].getStatus()) {
                cout << "Available" << endl;
            }
            else {
                cout << "Not Available" << endl;
            }
        }
    }

    // Search for a book by name
    void searchBook(string name) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getName() == name) {
                cout << "Book found! Details:" << endl;
                cout << books[i].getName() << " by " << books[i].getAuthor() << ", ID: " << books[i].getID() << ", Status: ";
                if (books[i].getStatus()) {
                    cout << "Available" << endl;
                }
                else {
                    cout << "Not Available" << endl;
                }
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    // Borrow a book
    void borrowBook(int ID) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getID() == ID) {
                if (books[i].getStatus()) {
                    books[i].setStatus(false);
                    cout << "Book borrowed successfully!" << endl;
                }
                else {
                    cout << "Sorry, the book is not available for borrowing at the moment." << endl;
                }
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    // Return a book
    void returnBook(int ID) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getID() == ID) {
                books[i].setStatus(true);
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
