/**
 * @file UserManager.hpp
 * @author Navneet Desai
 * @brief 
 * @version 0.1
 * @date 2023-06-07
 * 
 * 
 */
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <string>
#include <vector>
#include "cipherlock.hpp"


struct User {
    std::string username;
    std::string password;
};

struct Password {
    std::string username;
    std::string identifier;
    std::string password;
};

class UserManager {
public:
    explicit UserManager(const std::string& filename);

    bool register_user(const std::string& username, const std::string& password);
    bool login_user(const std::string& username, const std::string& password);
    std::vector<std::vector<std::string>> list_passwords(const std::string& username);
    bool store_password(const std::string& username, const std::string& password);
    void remove_user(const std::string& username);
    void set_cipher(CipherLock cipher);
    std::string get_password(const std::string& username);
    CipherLock get_cipher();

private:
    std::string filename;
    std::vector<User> users;
    std::vector<Password> passwords;
    bool _is_logged_in;
    User _logged_in_user;
    CipherLock cipher;

    bool is_user_exists(const std::string& username);
    void load_users();
    void load_passwords();
    void save_users();
    
    
};

#endif
