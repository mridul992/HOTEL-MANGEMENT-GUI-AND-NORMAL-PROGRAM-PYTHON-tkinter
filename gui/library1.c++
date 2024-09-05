#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Book {
private:
    string bookName;
    string authorName;
    string publisher;
    int isbnNumber;
    int publicationYear;
    int numberOfCopies;
    int availableCopies;

public:
    Book() {}
    Book(string bookName, string authorName, string publisher, int isbnNumber, int publicationYear, int numberOfCopies) {
        this->bookName = bookName;
        this->authorName = authorName;
        this->publisher = publisher;
        this->isbnNumber = isbnNumber;
        this->publicationYear = publicationYear;
        this->numberOfCopies = numberOfCopies;
        this->availableCopies = numberOfCopies;
    }

    // Getter methods
    string getBookName() { return bookName; }
    string getAuthorName() { return authorName; }
    string getPublisher() { return publisher; }
    int getISBNNumber() { return isbnNumber; }
    int getPublicationYear() { return publicationYear; }
    int getNumberOfCopies() { return numberOfCopies; }
    int getAvailableCopies() { return availableCopies; }

    // Setter methods
    void setBookName(string bookName) { this->bookName = bookName; }
    void setAuthorName(string authorName) { this->authorName = authorName; }
    void setPublisher(string publisher) { this->publisher = publisher; }
    void setISBNNumber(int isbnNumber) { this->isbnNumber = isbnNumber; }
    void setPublicationYear(int publicationYear) { this->publicationYear = publicationYear; }
    void setNumberOfCopies(int numberOfCopies) { this->numberOfCopies = numberOfCopies; }
    void setAvailableCopies(int availableCopies) { this->availableCopies = availableCopies; }

    void display() {
        cout << "Book Name: " << bookName << endl;
        cout << "Author Name: " << authorName << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN Number: " << isbnNumber << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
        cout << "Available Copies: " << availableCopies << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string bookName, authorName, publisher;
        int isbnNumber, publicationYear, numberOfCopies;

        cout << "Enter book name: ";
        getline(cin, bookName);
        cout << "Enter author name: ";
        getline(cin, authorName);
        cout << "Enter publisher: ";
        getline(cin, publisher);
        cout << "Enter ISBN number: ";
        cin >> isbnNumber;
        cout << "Enter publication year: ";
        cin >> publicationYear;
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;

        Book newBook(bookName, authorName, publisher, isbnNumber, publicationYear, numberOfCopies);
        books.push_back(newBook);

        cout << endl << "Book added successfully!" << endl << endl;
    }

    void displayAllBooks() {
        cout << "Books available in the library:" << endl << endl;

        for (int i = = 0; i < books.size(); i++) {
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