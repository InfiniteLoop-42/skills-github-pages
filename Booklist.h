#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"
#include "User.h"
#include <string>
#include <iostream>

class BookList 
{
private:
    Book* books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int capacity);
    void addBook(const Book& book);
    Book* searchBook(std::string title);
    Book* searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    void getBooksForUser(const User& user);
    Book& operator[](int index);
    friend std::ostream& operator<<(std::ostream& output, const BookList& booklist);
    ~BookList();
};

#endif
