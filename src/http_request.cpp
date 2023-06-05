#include "http_request.hpp"

HttpRequest::HttpRequest(const std::string& method, const std::string& path, const std::unordered_map<std::string, std::string>& headers, const std::string& body)
    : method(method), path(path), headers(headers), body(body) {}

std::string HttpRequest::getMethod() const {
    return method;
}

std::string HttpRequest::getPath() const {
    return path;
}

std::string HttpRequest::getHeader(const std::string& key) const {
    auto it = headers.find(key);
    if (it != headers.end()) {
        return it->second;
    }
    return "";
}

std::string HttpRequest::getBody() const {
    return body;
}
