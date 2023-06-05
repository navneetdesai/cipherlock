#include "user_manager.hpp"

void UserManager::registerUser(const std::string& username, const std::string& password, const std::string& email) {
    // Create a new User object using the provided parameters
    User newUser(username, password, email);

    // Add the new user to the users vector
    users.push_back(newUser);
}
