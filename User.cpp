#include "User.h"
#include <iostream>
int User::count=0;
User::User()
{
    name = "";
    age = 0;
    email = "";
    count++;
    id = count;
}


User::User(std::string name, int age, std::string email)
{
    this->name = name;
    this->age = age;
    this->email = email;
    count++;
    id = count;
}

User::User(const User& user)
{
    name = user.name;
    age = user.age;
    email = user.email;
    id = user.id;
}

void User::setName(std::string name)
{
    this->name = name;
}

std::string User::getName() const
{
    return name;
}

void User::setAge(int age)
{
    this->age = age;
}

int User::getAge() const
{
    return age;
}

void User::setEmail(std::string email)
{
    this->email = email;
}

std::string User::getEmail() const
{
    return email;
}

void User::setId(int id)
{
    this->id = id;
}

int User::getId() const
{
    return id;
}

bool User::operator==(const User& user) const
{
    return (this->name == user.name && 
            this->age == user.age && 
            this->email == user.email && 
            this->id == user.id);
}

std::ostream& operator<<(std::ostream& output, const User& user)
{
    output << "=======User " << user.id << " info========" << std::endl;
    output << "Name: " << user.name;
    output << "  ||  Age: " << user.age;
    output << "  ||  ID: " << user.id;
    output << "  ||  Email: " << user.email << std::endl;
    output << "=========================================" << std::endl;
    
    return output;
}

std::istream& operator>>(std::istream& input, User& user)
{
    std::cout << "Enter user information in this order >>" << std::endl;
    std::cout << "Name: Age: Email: " << std::endl;
    input >> user.name >> user.age >> user.email;
    return input;
}
