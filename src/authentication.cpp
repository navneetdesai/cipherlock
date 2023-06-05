#include "authentication.hpp"

Authentication::Authentication() {
    credentials_["user1"] = "password1";
    credentials_["user2"] = "password2";
    credentials_["user3"] = "password3";
}

bool Authentication::loginUser(const std::string& username, const std::string& password) {
    if (validateCredentials(username, password)) {
        return true;
    }
    return false;
}

bool Authentication::validateCredentials(const std::string& username, const std::string& password) {
    if (credentials_.count(username) > 0 && credentials_[username] == password) {
        return true;
    }
    return false;
}

std::string Authentication::generateAuthToken(const std::string& username) {
    // Generate and return a unique authentication token for the user (Replace with your own token generation logic)
    return "sample_auth_token";
}
