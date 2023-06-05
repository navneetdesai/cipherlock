#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
private:
    std::string username;
    std::string password;
    std::string email;

public:
    User(const std::string& username, const std::string& password, const std::string& email);
    
    std::string getUsername() const;
    void setUsername(const std::string& username);
    
    std::string getPassword() const;
    void setPassword(const std::string& password);
    
    std::string getEmail() const;
    void setEmail(const std::string& email);
};

#endif // USER_HPP
