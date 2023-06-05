#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <vector>
#include "user.hpp"

class UserManager {
private:
    std::vector<User> users;

public:
    void registerUser(const std::string& username, const std::string& password, const std::string& email);
    // Add any additional functions you may need for user management
};

#endif // USER_MANAGER_HPP
