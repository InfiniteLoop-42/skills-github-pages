#ifndef BOOK_H
#define BOOK_H
#include "User.h"
#include <string>
#include <iostream>

// Forward declaration to avoid circular dependency
class User;

class Book
{
private:
    User* author;
    std::string title;
    std::string isbn;
    int id;
    std::string category;
    double averageRating;
    bool hasAuthor;
    int numRate;
    double sumRate;
public:
    static int count;
    Book();
    Book(std::string title, std::string category, std::string isbn);
    Book(const Book& book);
    void setTitle(std::string title);
    std::string getTitle() const;
    void setIsbn(std::string isbn);
    std::string getIsbn() const;
    void setId(int id);
    int getId() const;
    void setCategory(std::string category);
    std::string getCategory() const;
    void setAuthor(const User& user);
    User getAuthor() const;
    void rateBook(double rating);
    double getAverageRating() const;
    bool operator==(const Book& book);
    friend std::ostream& operator<<(std::ostream& output, const Book& book);
    friend std::istream& operator>>(std::istream& input, Book& book);
};

#endif
