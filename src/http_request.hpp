#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <unordered_map>

class HttpRequest {
private:
    std::string method;
    std::string path;
    std::unordered_map<std::string, std::string> headers;
    std::string body;

public:
    HttpRequest(const std::string& method, const std::string& path, const std::unordered_map<std::string, std::string>& headers, const std::string& body);

    std::string getMethod() const;
    std::string getPath() const;
    std::string getHeader(const std::string& key) const;
    std::string getBody() const;
};

#endif // HTTP_REQUEST_HPP
