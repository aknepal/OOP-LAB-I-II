#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Library {
private:
    struct Book {
        string bookTitle;
        string ISBN;
        string author;
        int numberOfCopies;

        Book(string isbn, string title, string auth, int copies)
            : ISBN(isbn), bookTitle(title), author(auth), numberOfCopies(copies) {}
    };
    
    vector<Book> catalog;
    
     void loadFromFile(){
     
        ifstream inFile("library_catalog.txt");
        catalog.clear();
        string isbn, title, auth;
        int copies;
        while (inFile >> isbn >> title >> auth >> copies) {
            catalog.emplace_back(isbn, title, auth, copies);
        }
        inFile.close();
    }
    
    void saveToFile() {
        ofstream outFile("library_catalog.txt");
        for (const auto& book : catalog) {
            outFile << book.ISBN << "\t" << book.bookTitle << "\t" << book.author << "\t" << book.numberOfCopies << "\n";
        }
        outFile.close();
    }

    
    bool findBookByISBN(const string& isbn, size_t& index) {
        for (size_t i = 0; i < catalog.size(); ++i) {
            if (catalog[i].ISBN == isbn) {
                index = i;
                return true;
            }
        }
        return false;
    }

public:
    Library() {
        loadFromFile();
    }

    ~Library() {
        saveToFile();
    }

    void addNewBook() {
        string isbn, title, auth;
        int copies;
        cout << "Enter ISBN: ";
        cin >> isbn;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, auth);
        cout << "Enter Number of Copies: ";
        cin >> copies;

        size_t index;
        if (!findBookByISBN(isbn, index)) {
            catalog.emplace_back(isbn, title, auth, copies);
            saveToFile();
            cout << "Book added ." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " already exists." << endl;
        }
    }

    void issueBook() {
        string isbn;
        cout << "Enter ISBN to issue: ";
        cin >> isbn;

        size_t index;
        if (findBookByISBN(isbn, index)) {
            if (catalog[index].numberOfCopies > 0) {
                catalog[index].numberOfCopies--;
                saveToFile();
                cout << "Book issued ." << endl;
            } else {
                cout << "No copies available for issuing." << endl;
            }
        } else {
            cout << "Book not found on library." << endl;
        }
    }

    void returnBook() {
        string isbn;
        cout << "Enter ISBN to return: ";
        cin >> isbn;

        size_t index;
        if (findBookByISBN(isbn, index)) {
            catalog[index].numberOfCopies++;
            saveToFile();
            cout << "Book returned ." << endl;
        } else {
            cout << "Book not found on library." << endl;
        }
    }

    void updateBookDetails() {
        string isbn, newTitle, newAuth;
        int newCopies;
        cout << "Enter ISBN to update the book detail: ";
        cin >> isbn;

        size_t index;
        if (findBookByISBN(isbn, index)) {
            cout << "Enter New Book Title: ";
            cin.ignore();
            getline(cin, newTitle);
            cout << "Enter New Author: ";
            getline(cin, newAuth);
            cout << "Enter New Number of Copies: ";
            cin >> newCopies;

            catalog[index].bookTitle = newTitle;
            catalog[index].author = newAuth;
            catalog[index].numberOfCopies = newCopies;
            saveToFile();
            cout << "Book details updated ." << endl;
        } else {
            cout << "Book not found on library ." << endl;
        }
    }

    void deleteBook() {
        string isbn;
        cout << "Enter ISBN to delete: ";
        cin >> isbn;

        size_t index;
        if (findBookByISBN(isbn, index)) {
            if (catalog[index].numberOfCopies == 0) {
                catalog.erase(catalog.begin() + index);
                saveToFile();
                cout << "Book deleted ." << endl;
            } else {
                cout << "Cannot delete copies available" << endl;
            }
        } else {
            cout << "Book not found on the library." << endl;
        }
    }

    void displayBooks() {
        cout << "ISBN\t\tTitle\t\tAuthor\t\tCopies" << endl;
        for (const auto& book : catalog) {
            cout << book.ISBN << "\t\t" << book.bookTitle << "\t\t" << book.author << "\t\t" << book.numberOfCopies << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\nLibrary Menu\n";
        cout << "1. Add New Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Update Book Details\n";
        cout << "5. Delete Book\n";
        cout << "6. Display All Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addNewBook();
                break;
            case 2:
                lib.issueBook();
                break;
            case 3:
                lib.returnBook();
                break;
            case 4:
                lib.updateBookDetails();
                break;
            case 5:
                lib.deleteBook();
                break;
            case 6:
                lib.displayBooks();
                break;
            case 0:
                cout << "Exiting the library system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
