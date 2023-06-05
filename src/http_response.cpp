#include "http_response.hpp"

HttpResponse::HttpResponse(int statusCode, const std::unordered_map<std::string, std::string>& headers, const std::string& body)
    : statusCode(statusCode), headers(headers), body(body) {}

int HttpResponse::getStatusCode() const {
    return statusCode;
}

void HttpResponse::setStatusCode(int statusCode) {
    this->statusCode = statusCode;
}

std::string HttpResponse::getHeader(const std::string& key) const {
    auto it = headers.find(key);
    if (it != headers.end()) {
        return it->second;
    }
    return "";
}

void HttpResponse::setHeader(const std::string& key, const std::string& value) {
    headers[key] = value;
}

std::string HttpResponse::getBody() const {
    return body;
}

void HttpResponse::setBody(const std::string& body) {
    this->body = body;
}
