#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <string>
#include <vector>


struct User {
    std::string username;
    std::string password;
};

class UserManager {
public:
    explicit UserManager(const std::string& filename);

    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    std::vector<std::string> listPasswords(const std::string& username);
    void removeUser(const std::string& username);

private:
    std::string filename;
    std::vector<User> users;

    bool isUserExists(const std::string& username);
    void loadUsers();
    void saveUsers();
};

#endif
