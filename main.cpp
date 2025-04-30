
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
#include <iostream>
#include <string>

void main_menu() {
    std::cout << "Select one of the following choices: " << std::endl;
    std::cout << "1- Books Menu" << std::endl;
    std::cout << "2- Users Menu" << std::endl;
    std::cout << "3- Exit " << std::endl;
}

void user_menu() {
    std::cout << " USERS MENU" << std::endl;
    std::cout << "1- Create a USER and add it to the list " << std::endl;
    std::cout << "2- Search for a user " << std::endl;
    std::cout << "3- Display all users " << std::endl;
    std::cout << "4- Back to the main " << std::endl;
}

void search_user_menu() {
    std::cout << "SEARCH FOR A USER" << std::endl;
    std::cout << "1- Search by name" << std::endl;
    std::cout << "2- Search by id" << std::endl;
    std::cout << "3- Return to users Menu" << std::endl;
}

void delete_user_menu() {
    std::cout << "1- Delete user " << std::endl;
    std::cout << "2- Return to users Menu" << std::endl;
}

void book_menu() {
    std::cout << "BOOKS MENU" << std::endl;
    std::cout << "1- Create a book and add it to the list " << std::endl;
    std::cout << "2- Search for a book" << std::endl;
    std::cout << "3- Display all books (with book rating)" << std::endl;
    std::cout << "4- Get the highest rating" << std::endl;
    std::cout << "5- Get all books of a user " << std::endl;
    std::cout << "6- Back to the main menu" << std::endl;
}

void search_book_menu() {
    std::cout << "SEARCH FOR A BOOK" << std::endl;
    std::cout << "1- Search by name" << std::endl;
    std::cout << "2- Search by id" << std::endl;
    std::cout << "3- Return to Books Menu" << std::endl;
}

void search_book_name() {
    std::cout << "1- Update author" << std::endl;
    std::cout << "2- Update name" << std::endl;
    std::cout << "3- Update Category" << std::endl;
    std::cout << "4- Delete Book" << std::endl;
    std::cout << "5- Rate book" << std::endl;
    std::cout << "6- Get back to books menu" << std::endl;
}

int main() {
    bool b1 = true, b2 = true, b3 = true, b4 = false, b5 = false;
    bool b6 = true, b7 = true, b8 = true, b9 = false;
    int choice1, choice2, choice3, choice4, choice5;
    int choice6, choice7, choice8, choice9;
    UserList* U = NULL;
    BookList* B =NULL;
    
    while (b1) {
        main_menu();
        std::cin >> choice1;
        
        switch (choice1) {
        case 1:
            {
                int NumberOfBooks;
                std::cout << "How many books will be added?" << std::endl;
                std::cin >> NumberOfBooks;
                B = new BookList(NumberOfBooks);
                b6 = true;
                
                while (b6) {
                    book_menu();
                    std::cin >> choice6;
                    
                    switch (choice6) {
                    case 1:
                        {
                            Book b1;
                            std::cin >> b1;
                            
                            b8 = true;
                            while (b8) {
                                std::cout << "1- Assign Author" << std::endl;
                                std::cout << "2- Continue" << std::endl;
                                std::cin >> choice8;
                                
                                switch (choice8) {
                                case 1:
                                    {
                                        std::cout << "Enter author (user) id: " << std::endl;
                                        int id;
                                        std::cin >> id;
                                        
                                        if (U == NULL) {
                                            std::cout << "No user list initialized yet. Please create users first." << std::endl;
                                            break;
                                        }
                                        
                                        User* u4 = U->searchUser(id);
                                        if (u4 == NULL) {
                                            std::cout << "No Author Found with id = " << id << std::endl;
                                        }
                                        else {
                                            b1.setAuthor(*u4);
                                            B->addBook(b1);
                                            b8 = false;
                                        }
                                    }
                                    break;
                                case 2:
                                    B->addBook(b1);
                                    b8 = false;
                                    break;
                                default:
                                    b8 = false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 2:
                        {
                            b7 = true;
                            while (b7) {
                                search_book_menu();
                                std::cin >> choice7;
                                
                                switch (choice7) {
                                case 1:
                                    {
                                        std::string ss;
                                        std::cout << "Enter Name: " << std::endl;
                                        std::cin >> ss;
                                        Book* b2 = B->searchBook(ss);
                                        
                                        if (b2 == NULL) {
                                            std::cout << "Name Not Found " << std::endl;
                                            b9 = false;
                                        }
                                        else {
                                            b9 = true;
                                            std::cout << *b2;
                                            
                                            while (b9) {
                                                search_book_name();
                                                std::cin >> choice9;
                                                
                                                switch (choice9) {
                                                case 1:
                                                    {
                                                        std::cout << "Enter author (user) id: " << std::endl;
                                                        int id;
                                                        std::cin >> id;
                                                        
                                                        if (U ==NULL) {
                                                            std::cout << "No user list initialized yet. Please create users first." << std::endl;
                                                            break;
                                                        }
                                                        
                                                        User* uu = U->searchUser(id);
                                                        if (uu == NULL) {
                                                            std::cout << "No Author Found with id = " << id << std::endl;
                                                        }
                                                        else {
                                                            b2->setAuthor(*uu);
                                                        }
                                                    }
                                                    break;
                                                case 2:
                                                    {
                                                        std::cout << "Enter new name: " << std::endl;
                                                        std::string str;
                                                        std::cin >> str;
                                                        b2->setTitle(str);
                                                    }
                                                    break;
                                                case 3:
                                                    {
                                                        std::cout << "Enter new Category: " << std::endl;
                                                        std::string str;
                                                        std::cin >> str;
                                                        b2->setCategory(str);
                                                    }
                                                    break;
                                                case 4:
                                                    {
                                                        B->deleteBook(b2->getId());
                                                        b9 = false;
                                                    }
                                                    break;
                                                case 5:
                                                    {
                                                        std::cout << "Enter Rating value: " << std::endl;
                                                        double rate_value;
                                                        std::cin >> rate_value;
                                                        b2->rateBook(rate_value);
                                                    }
                                                    break;
                                                case 6:
                                                    b9 = false;
                                                    break;
                                                default:
                                                    b9 = false;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                    {
                                        int ID;
                                        std::cout << "Enter ID: " << std::endl;
                                        std::cin >> ID;
                                        Book* b3 = B->searchBook(ID);
                                        
                                        if (b3 == NULL) {
                                            std::cout << "ID Not Found " << std::endl;
                                        }
                                        else {
                                            std::cout << *b3;
                                        }
                                    }
                                    break;
                                case 3:
                                    b7 = false;
                                    break;
                                default:
                                    b7 = false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 3:
                        std::cout << *B;
                        break;
                    case 4:
                        {
                            Book b4 = B->getTheHighestRatedBook();
                            std::cout << b4;
                        }
                        break;
                    case 5:
                        {
                            if (U == NULL) {
                                std::cout << "No user list initialized yet. Please create users first." << std::endl;
                                break;
                            }
                            
                            int ID;
                            std::cout << "Enter ID" << std::endl;
                            std::cin >> ID;
                            User* u5 = U->searchUser(ID);
                            
                            if (u5 == NULL) {
                                std::cout << "No Author Found with id = " << ID << std::endl;
                            }
                            else {
                                B->getBooksForUser(*u5);
                            }
                        }
                        break;
                    case 6:
                        b6 = false;
                        break;
                    default:
                        b6 = false;
                        break;
                    }
                }
            }
            break;
        case 2:
            {
                int NumberOfUsers;
                std::cout << "How many users will be added?" << std::endl;
                std::cin >> NumberOfUsers;
                U = new UserList(NumberOfUsers);
                b2 = true;
                
                while (b2) {
                    user_menu();
                    std::cin >> choice2;
                    
                    switch (choice2) {
                    case 1:
                        {
                            User u1;
                            std::cin >> u1;
                            U->addUser(u1);
                        }
                        break;
                    case 2:
                        {
                            b3 = true;
                            while (b3) {
                                search_user_menu();
                                std::cin >> choice3;
                                
                                switch (choice3) {
                                case 1:
                                    {
                                        std::string s;
                                        std::cout << "Enter Name: " << std::endl;
                                        std::cin >> s;
                                        User* u2 = U->searchUser(s);
                                        
                                        if (u2 == NULL) {
                                            std::cout << "Name Not Found" << std::endl;
                                            b3 = false;
                                            b4 = false;
                                        }
                                        else {
                                            std::cout << *u2 << std::endl;
                                            b4 = true;
                                            
                                            while (b4) {
                                                delete_user_menu();
                                                std::cin >> choice4;
                                                
                                                switch (choice4) {
                                                case 1:
                                                    U->deleteUser(u2->getId());
                                                    b4 = false;
                                                    break;
                                                case 2:
                                                    b4 = false;
                                                    break;
                                                default:
                                                    b4 = false;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                case 2:
                                    {
                                        int id;
                                        std::cout << "Enter ID: " << std::endl;
                                        std::cin >> id;
                                        User* u3 = U->searchUser(id);
                                        
                                        if (u3 == NULL) {
                                            std::cout << "ID Not Found" << std::endl;
                                            b5 = false;
                                        }
                                        else {
                                            std::cout << *u3;
                                            b5 = true;
                                            
                                            while (b5) {
                                                delete_user_menu();
                                                std::cin >> choice5;
                                                
                                                switch (choice5) {
                                                case 1:
                                                    U->deleteUser(u3->getId());
                                                    b5 = false;
                                                    break;
                                                case 2:
                                                    b5 = false;
                                                    break;
                                                default:
                                                    b5 = false;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                case 3:
                                    b3 = false;
                                    break;
                                default:
                                    b3 = false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 3:
                        std::cout << *U;
                        break;
                    case 4:
                        b2 = false;
                        break;
                    default:
                        b2 = false;
                        break;
                    }
                }
            }
            break;
        case 3:
            b1 = false;
            break;
        default:
            b1 = false;
            break;
        }
    }
    
    delete U;
    delete B;
    
    return 0;
}
