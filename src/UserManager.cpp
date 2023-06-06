#include "UserManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "cipherlock.hpp"

UserManager::UserManager(const std::string& filename) : filename(filename) {
    cipher = CipherLock(0);
    load_users();
    load_passwords();
    _is_logged_in = false;
}

bool UserManager::register_user(const std::string& username, const std::string& password) {
    if (is_user_exists(username)) {
        std::cerr << "User already exists" << std::endl;
        return false; // User already exists
    }
    std::string encrypted_password = cipher.encrypt(password);
    users.push_back({username, encrypted_password});
    save_users();
    return true;
}

bool UserManager::login_user(const std::string& username, const std::string& password) {
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            _is_logged_in = true;
            return _is_logged_in; // Login successful
        }
    }
    return false; // Login failed
}

std::vector<std::string> UserManager::list_passwords(const std::string& username) {
    std::vector<std::string> passwords;

    for (const User& user : users) {
        if (user.username == username) {
            passwords.push_back(user.password);
        }
    }

    return passwords;
}

void UserManager::remove_user(const std::string& username) {
    auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
        return user.username == username;
    });

    if (it != users.end()) {
        users.erase(it, users.end());
        save_users();
    }
}

bool UserManager::is_user_exists(const std::string& username) {
    for (const User& user : users) {
        if (user.username == username) {
            return true;
        }
    }
    return false;
}

void UserManager::load_users() {
    std::ifstream file(filename);
    if (!file) {
        return; 
    }

    users.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::string username, password;
        std::istringstream iss(line);
        if (iss >> username >> password) {
            users.push_back({username, password});
        }
    }

    file.close();
}

void UserManager::load_passwords() {
    std::ifstream file("passwords.txt");
    if (!file) {
        return; 
    }

    passwords.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::string username, password;
        std::istringstream iss(line);
        if (iss >> username >> password) {
            passwords.push_back({username, password});
        }
    }

    file.close();
}



bool UserManager::store_password(const std::string& username, const std::string& password) {
    std::ofstream file("passwords.txt");
    if (!_is_logged_in) {
        std::cerr << "You must be logged in to store a password" << std::endl;
        return false;
    }
    if (!file) {
        std::cerr << "There was an issue with password retrieval" << std::endl;
        return false;
    }
    
    for (const User& user : users) {
        file << user.username << " " << user.password << std::endl;
    }

    file.close();
    return true;
}



void UserManager::save_users() {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const User& user : users) {
        file << user.username << " " << user.password << std::endl;
    }

    file.close();
}

CipherLock UserManager::get_cipher() {
    return cipher;
}

void UserManager::set_cipher(CipherLock cipher) {
    this->cipher = cipher;
}
