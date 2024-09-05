#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
    public:
        string title;
        string author;
        int pages;
        bool checkedOut;
};

class Library {
    private:
        Book books[MAX_BOOKS];
        int numOfBooks;
    public:
        Library() {
            numOfBooks = 0;
        }

        void addBook(string title, string author, int pages) {
            Book newBook;
            newBook.title = title;
            newBook.author = author;
            newBook.pages = pages;
            newBook.checkedOut = false;
            books[numOfBooks] = newBook;
            numOfBooks++;
            cout << "Book added successfully." << endl;
        }

        void removeBook(int index) {
            for (int i = index; i < numOfBooks - 1; i++) {
                books[i] = books[i+1];
            }
            numOfBooks--;
            cout << "Book removed successfully." << endl;
        }

        void displayBooks() {
            for (int i = 0; i < numOfBooks; i++) {
                cout << books[i].title << " by " << books[i].author << " (" << books[i].pages << " pages)" << endl;
            }
        }

        void checkoutBook(int index) {
            if (books[index].checkedOut) {
                cout << "Sorry, this book is already checked out." << endl;
            } else {
                books[index].checkedOut = true;
                cout << "You have checked out " << books[index].title << "." << endl;
            }
        }

        void returnBook(int index) {
            if (!books[index].checkedOut) {
                cout << "This book has not been checked out." << endl;
            } else {
                books[index].checkedOut = false;
                cout << "You have returned " << books[index].title << "." << endl;
            }
        }
};

int main() {
    Library library;

    // Add some books
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 224);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 281);
    library.addBook("1984", "George Orwell", 328);

    int choice;
    do {
        cout << "Library Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Check Out Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                string title, author;
                int pages;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter number of pages: ";
                cin >> pages;
                library.addBook(title, author, pages);
                break;
            case 2:
                int index;
                cout << "Enter index of book to remove: ";
                cin >> index;
                library.removeBook(index);
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout();
                break;
}

