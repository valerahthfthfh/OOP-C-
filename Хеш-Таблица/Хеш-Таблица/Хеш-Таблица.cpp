#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string nameBook;
    string author;
    int year;
    int ID;

public:
    
    Book(string nameBook, string author, int year, int ID) {
        this->nameBook = nameBook;
        this->author = author;
        this->year = year;
        this->ID = ID;
    }

    string getName() const {
        return nameBook;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    int getID() const {
        return ID;
    }

    void output() const {
        cout << ID << " | " << nameBook << " | " << author << " | " << year << endl;
    }
};

class Library{
private:
    vector<Book> books;
    string libraryName;

public:

    Library(string name) {
        this->libraryName = name;
    }

    void addBook(const Book& book) {
        books.push_back(book);
    }
    // поиск
    void findBookName(const string& name) {
        cout << "Books name The '" << name << endl;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getName() == name)
                books[i].output();
        }
    }

    void outputAllBooks() {
        cout << "Library: " << libraryName << endl;
        cout << "All books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            books[i].output();
        }
    }

    bool removeBook(int ID) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getID() == ID) {
                books.erase(books.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Library myLibrary("Central Library");

    // gpt
    myLibrary.addBook(Book("1984", "George Orwell", 1949, 1));
    myLibrary.addBook(Book("Animal Farm", "George Orwell", 1945, 2));
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932, 3));
    myLibrary.addBook(Book("1984", "Another Author", 2000, 4));

    
    myLibrary.outputAllBooks();
    cout << endl;

    
    myLibrary.findBookName("Animal Farm");
    cout << endl;

    
    myLibrary.removeBook(2);
        

    myLibrary.outputAllBooks();
}
