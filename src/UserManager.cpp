#include "UserManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

UserManager::UserManager(const std::string& filename) : filename(filename) {
    loadUsers();
}

bool UserManager::registerUser(const std::string& username, const std::string& password) {
    if (isUserExists(username)) {
        return false; // User already exists
    }

    users.push_back({username, password});
    saveUsers();
    return true;
}

bool UserManager::loginUser(const std::string& username, const std::string& password) {
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}

std::vector<std::string> UserManager::listPasswords(const std::string& username) {
    std::vector<std::string> passwords;

    for (const User& user : users) {
        if (user.username == username) {
            passwords.push_back(user.password);
        }
    }

    return passwords;
}

void UserManager::removeUser(const std::string& username) {
    auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
        return user.username == username;
    });

    if (it != users.end()) {
        users.erase(it, users.end());
        saveUsers();
    }
}

bool UserManager::isUserExists(const std::string& username) {
    for (const User& user : users) {
        if (user.username == username) {
            return true;
        }
    }
    return false;
}

void UserManager::loadUsers() {
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

void UserManager::saveUsers() {
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
