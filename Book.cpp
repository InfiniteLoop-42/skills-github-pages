#include "Book.h"
#include "User.h"
#include <iostream>

int Book::count = 0;

Book::Book()
{
    title = "";
    isbn = "";
    category = "";
    averageRating = 0.0;
    count++;
    id = count;
    hasAuthor = false;
    author = NULL;
    numRate = 0;
    sumRate = 0;
}

Book::Book(std::string title, std::string category, std::string isbn) 
{
    this->title = title;
    this->category = category;
    this->isbn = isbn;
    averageRating = 0.0;
    count++;
    id = count;
    hasAuthor = false;
    author = NULL;
    numRate = 0;
    sumRate = 0;
}

Book::Book(const Book& book) 
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    id = book.id;
    averageRating = book.averageRating;
    hasAuthor = book.hasAuthor;
    numRate = book.numRate;
    sumRate = book.sumRate;
    
    if (book.hasAuthor)
    {
        setAuthor(book.getAuthor());
    }
    else
    {
        author =NULL;
    }
}

void Book::setTitle(std::string title)
{
    this->title = title;
}

std::string Book::getTitle() const
{
    return title;
}

void Book::setIsbn(std::string isbn)
{
    this->isbn = isbn;
}

std::string Book::getIsbn() const
{
    return isbn;
}

void Book::setId(int id)
{
    this->id = id;
}

int Book::getId() const
{
    return id;
}

void Book::setCategory(std::string category)
{
    this->category = category;
}

std::string Book::getCategory() const
{
    return category;
}

void Book::setAuthor(const User& user)
{
    hasAuthor = true;
    author = new User(user);
}

User Book::getAuthor() const
{
    if (hasAuthor)
        return *author;
    
    return User();
}

double Book::getAverageRating() const
{
    return averageRating;
}

void Book::rateBook(double rating)
{
    numRate++;
    sumRate += rating;
    averageRating = sumRate / numRate;
}

bool Book::operator==(const Book& book)
{
    return (this->title == book.title && 
            this->id == book.id && 
            this->category == book.category && 
            this->averageRating == book.averageRating);
}

std::istream& operator>>(std::istream& input, Book& book)
{
    std::cout << "Enter the book information in this order >> " << std::endl;
    std::cout << "Title: Category: " << std::endl;
    input >> book.title >> book.category;
    book.averageRating = 0.0;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Book& book)
{
    output << "=======Book==" << book.id << "info========" << std::endl;
    output << "Title: " << book.title;
    output << "  ||  ID: " << book.id;
    output << "  ||  Category: " << book.category;
    output << "  ||  Avg Rating: " << book.averageRating << std::endl;

    if (book.hasAuthor)
    {
        output << book.getAuthor();
    }
    output << "=========================================" << std::endl;

    return output;
}
