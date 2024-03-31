#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string ISBN;
    std::string title;
    std::string author;
    bool available;

    Book(std::string isbn, std::string bookTitle, std::string bookAuthor)
        : ISBN(isbn), title(bookTitle), author(bookAuthor), available(true) {}
};

class User {
public:
    std::string userID;
    std::vector<Book*> borrowedBooks;

    User(std::string id) : userID(id) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void displayAvailableBooks() {
        std::cout << "available books:" << std::endl;
        for (const auto& book : books) {
            if (book.available) {
                std::cout << "ISBN: " << book.ISBN << ", title: \"" << book.title << "\", author: \"" << book.author << "\", status: available" << std::endl;
            }
        }
    }

    void displayBorrowedBooksByUser(const std::string& userID) {
        std::cout << "borrowed books by user " << userID << ":" << std::endl;
        for (const auto& user : users) {
            if (user.userID == userID) {
                for (const auto& book : user.borrowedBooks) {
                    std::cout << "ISBN: " << book->ISBN << ", title: \"" << book->title << "\", tuthor: \"" << book->author << "\"" << std::endl;
                }
                return;
            }
        }
        std::cout << "user not found." << std::endl;
    }

    void borrowBook(const std::string& ISBN, const std::string& userID) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && book.available) {
                book.available = false;
                for (auto& user : users) {
                    if (user.userID == userID) {
                        user.borrowedBooks.push_back(&book);
                        std::cout << "book borrowed successfully!" << std::endl;
                        return;
                    }
                }
            }
        }
        std::cout << "book not available or user not found." << std::endl;
    } 

    void returnBook(const std::string& ISBN, const std::string& userID) {
        for (auto& user : users) {
            if (user.userID == userID) {
                for (auto it = user.borrowedBooks.begin(); it != user.borrowedBooks.end(); ++it) {
                    if ((*it)->ISBN == ISBN) {
                        (*it)->available = true;
                        user.borrowedBooks.erase(it);
                        std::cout << "book returned successfully!" << std::endl;
                        return;
                    }
                }
            }
        }
        std::cout << "book not borrowed by the user or user not found." << std::endl;
    }

    void addUser(const std::string& userID) {
        users.push_back(User(userID));
    }

    void addBook(const std::string& ISBN, const std::string& title, const std::string& author) {
        books.push_back(Book(ISBN, title, author));
    }
};

int main() {
    std::cout << "welcome to the library management system!" << std::endl;

    Library library;

    library.addUser("001");
    library.addUser("002");

    library.addBook("12345", "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("67890", "To Kill a Mockingbird", "Harper Lee");
    library.addBook("13579", "1984", "George Orwell");

    bool repeat = true;

    std::string userID;
    std::string borrowUserID;
    std::string borrowISBN;
    std::string returnUserID;
    std::string returnISBN;

while (repeat) {
    std::cout << "\n1. Display Available Books\n"
                 "2. Display Borrowed Books by User\n"
                 "3. Borrow a Book\n"
                 "4. Return a Book\n"
                 "5. Exit\n\n"
                 "Enter your choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            library.displayAvailableBooks();
            break;
        case 2:
            std::cout << "Enter your user ID: ";
            std::cin >> userID;
            library.displayBorrowedBooksByUser(userID);
            break;
        case 3:
            std::cout << "Enter the ISBN of the book you want to borrow: ";
            std::cin >> borrowISBN;
            std::cout << "Enter your user ID: ";
            std::cin >> borrowUserID;
            library.borrowBook(borrowISBN, borrowUserID);
            break;
        case 4:
            std::cout << "Enter the ISBN of the book you want to return: ";
            std::cin >> returnISBN;
            std::cout << "Enter your user ID: ";
            std::cin >> returnUserID;
            library.returnBook(returnISBN, returnUserID);
            break;
        case 5:
            repeat = false;
            std::cout << "Exiting the Library Management System. Thank you!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
      }
  }
  return 0;
}


