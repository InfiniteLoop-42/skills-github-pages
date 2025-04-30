#include "UserList.h"
#include <iostream>

UserList::UserList()
{
    capacity = 0;
    usersCount = 0;
    users =NULL;
}

UserList::UserList(int capacity)
{
    this->capacity = capacity;
    users = new User[capacity];
    usersCount = 0;
}

void UserList::addUser(const User& user)
{
    if (usersCount < capacity) {
        users[usersCount] = user;
        users[usersCount].setId(usersCount + 1);
        usersCount++;
    }
    else {
        std::cout << "Unable to add user. The list is full." << std::endl;
    }
}

User* UserList::searchUser(std::string name)
{
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getName() == name) {
            return &users[i];
        }
    }
    return NULL;
}

User* UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getId() == id) {
            return &users[i];
        }
    }
    return NULL;
}

void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getId() == id) {
            while (i < usersCount - 1) {
                users[i] = users[i + 1];
                users[i].setId(i + 1);
                i++;
            }
            usersCount--;
            break;
        }
    }
}

User& UserList::operator[](int index)
{
    if (index >= 0 && index < usersCount) {
        return users[index];
    }
    
    std::cout << "Index out of range. Returning first user." << std::endl;
    return users[0];
}

std::ostream& operator<<(std::ostream& output, const UserList& userList)
{
    for (int i = 0; i < userList.usersCount; i++) {
        output << userList.users[i];
    }
    return output;
}
User& User::operator=(const User& user) {
    
   
}


UserList::~UserList()
{
    delete[] users;
}
