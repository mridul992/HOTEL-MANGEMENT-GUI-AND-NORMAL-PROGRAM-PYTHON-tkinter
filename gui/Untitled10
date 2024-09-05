#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
    private:
        string title;
        string author;
        int pages;
        bool checkedOut;
    public:
        Book(string bookTitle, string bookAuthor, int bookPages) {
            title = bookTitle;
            author = bookAuthor;
            pages = bookPages;
            checkedOut = false;
        }

        string getTitle() {
            return title;
        }

        string getAuthor() {
            return author;
        }

        int getPages() {
            return pages;
        }

        bool isCheckedOut() {
            return checkedOut;
        }

        void setCheckedOut(bool status) {
            checkedOut = status;
        }
};

class Library {
    private:
        vector<Book> books;
        int numOfBooks;
    public:
        Library() {
            numOfBooks = 0;
        }

        void addBook(string title, string author, int pages) {
            Book newBook(title, author, pages);
            books.push_back(newBook);
            numOfBooks++;
        }

        void removeBook(int index) {
            books.erase(books.begin() + index);
            numOfBooks--;
        }

        void displayBooks() {
            for (int i = 0; i < numOfBooks; i++) {
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << " (" << books[i].getPages() << " pages)" << endl;
            }
        }

        void checkoutBook(int index) {
            if (books[index].isCheckedOut()) {
                cout << "Sorry, this book is already checked out." << endl;
            } else {
                books[index].setCheckedOut(true);
                cout << "You have checked out " << books[index].getTitle() << "." << endl;
            }
        }

        void returnBook(int index) {
            if (!books[index].isCheckedOut()) {
                cout << "This book has not been checked out." << endl;
            } else {
                books[index].setCheckedOut(false);
                cout << "You have returned " << books[index].getTitle() << "." << endl;
            }
        }
};

int main() {
    Library library;

    // Add some books
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 224);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 281);
    library.addBook("1984", "George Orwell", 328);

    // Display all books
    library.displayBooks();

    // Check out a book
    library.checkoutBook(0);

    // Display all books again
    library.displayBooks();

    // Return a book
    library.returnBook(0);

    // Display all books again
    library.displayBooks();

    return 0;
}
