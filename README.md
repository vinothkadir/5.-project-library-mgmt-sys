# project-library-mgmt-sys
 
Project Title: Library Management System

Project Description: Developed a console-based Library Management System in C++ to manage book borrowing and return processes for library users.

Technologies Used:
C++
Standard Template Library (STL)
Object-Oriented Programming (OOP) principles

Key Features:
Implemented classes for Book, User, and Library to model books, users, and the library management system.
Books can be added to the library with details such as ISBN, title, and author.
Users can be added to the system with unique user IDs.
Functionality to display available books, display borrowed books by a user, borrow a book, and return a book.
Error handling for scenarios such as unavailable books, invalid user IDs, or books not borrowed by the user.

Your Contribution:
Designed and implemented the Book, User, and Library classes, including functionalities for managing book borrowing and returns.
Developed user-friendly interfaces for users to interact with the library system.

Challenges and Solutions:
Managing the association between books and users, tracking book availability, and handling borrowing and return processes efficiently.
Solution: Implemented logic to update book availability status and manage book borrowing and return operations.

Results or Impact:
Created a functional Library Management System that facilitates easy book borrowing and return processes for library users.

Future Enhancements:
Implement additional features such as book reservation, fine calculation for late returns, and user authentication for enhanced security.

Time Complexity:

Searching for Books/Users:
Searching for books or users involves iterating through the respective vectors, resulting in a time complexity of O(N) or O(M), where N is the number of books and M is the number of users.

Borrowing/Returning Books:
Borrowing and returning books also require searching for books and users, resulting in a time complexity of O(N * M), where N is the number of books and M is the number of users.

Space Complexity:
Books and Users:
The space complexity for storing information about books and users is O(N + M), where N is the number of books and M is the number of users.

Borrowed Books:
Storing borrowed books as references in the User class adds O(M * K) space complexity, where M is the number of users and K is the average number of books borrowed by each user.



