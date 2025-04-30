#ifndef USERLIST_H
#define USERLIST_H
#include "User.h"
#include <string>
#include <iostream>

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList();
    UserList(int capacity);
    void addUser(const User& user);
    User* searchUser(std::string name);
    User* searchUser(int id);
    void deleteUser(int id);
    User& operator[](int index);
    User& operator=(const User&);
    friend std::ostream& operator<<(std::ostream& output, const UserList& userList);
    ~UserList();
};

#endif
