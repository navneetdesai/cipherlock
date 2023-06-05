#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include <unordered_map>
#include <string>

class Authentication {
public:
    Authentication();

    bool loginUser(const std::string& username, const std::string& password);
    bool validateCredentials(const std::string& username, const std::string& password);
    std::string generateAuthToken(const std::string& username);

private:
    std::unordered_map<std::string, std::string> credentials_;
};

#endif 
