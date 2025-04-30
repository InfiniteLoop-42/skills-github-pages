#include "BookList.h"
#include <iostream>

BookList::BookList()
{
    capacity = 0;
    booksCount = 0;
    books = NULL;
}

BookList::BookList(int capacity)
{
    this->capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
}

void BookList::addBook(const Book& book)
{
    if (booksCount < capacity) {
        books[booksCount] = book;
        books[booksCount].setId(booksCount + 1);
        booksCount++;
    }
    else {
        std::cout << "Unable to add book. The list is full." << std::endl;
    }
}

Book* BookList::searchBook(std::string title)
{
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getTitle() == title) {
            return &books[i];
        }
    }
    return NULL;
}

Book* BookList::searchBook(int id)
{
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            return &books[i];
        }
    }
    return NULL;
}

void BookList::deleteBook(int id)
{
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            while (i < booksCount - 1) {
                books[i] = books[i + 1];
                books[i].setId(i + 1);
                i++;
            }
            booksCount--;
            break;
        }
    }
}

Book BookList::getTheHighestRatedBook()
{
    if (booksCount == 0) {
        std::cout << "No books in the list." << std::endl;
        return Book();
    }
    
    int highestRatedIndex = 0;
    double highestRating = books[0].getAverageRating();
    
    for (int i = 1; i < booksCount; i++) {
        if (books[i].getAverageRating() > highestRating) {
            highestRating = books[i].getAverageRating();
            highestRatedIndex = i;
        }
    }
    
    return books[highestRatedIndex];
}

void BookList::getBooksForUser(const User& user)
{
    bool found = false;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getAuthor() == user) {
            std::cout << books[i] << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No books found for this user." << std::endl;
    }
}

Book& BookList::operator[](int index)
{
    if (index >= 0 && index < booksCount) {
        return books[index];
    }
    
    std::cout << "Index out of range. Returning first book." << std::endl;
    return books[0];
}

std::ostream& operator<<(std::ostream& output, const BookList& booklist)
{
    for (int i = 0; i < booklist.booksCount; i++) {
        output << booklist.books[i];
    }
    return output;
}

BookList::~BookList()
{
    delete[] books;
}
