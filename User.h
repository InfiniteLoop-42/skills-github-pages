#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

class User
{
private:
	std::string password;
    std::string name;
    int age;
    std::string email;
    int id;
public:
	User& operator=(const User&);
    static int count;
    User();
    User(std::string name, int age, std::string email);
    User(const User& user);
    
    void setName(std::string name);
    std::string getName() const;
    void setAge(int age);
    int getAge() const;
    void setEmail(std::string email);
    std::string getEmail() const;
    void setId(int id);
    int getId() const;
    void displayInfo();
    bool operator==(const User& user) const;
    
    friend std::ostream& operator<<(std::ostream& output, const User& user);
    friend std::istream& operator>>(std::istream& input, User& user);
};

#endif
