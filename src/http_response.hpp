#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>
#include <unordered_map>

class HttpResponse {
private:
    int statusCode;
    std::unordered_map<std::string, std::string> headers;
    std::string body;

public:
    HttpResponse(int statusCode, const std::unordered_map<std::string, std::string>& headers, const std::string& body);

    int getStatusCode() const;
    void setStatusCode(int statusCode);

    std::string getHeader(const std::string& key) const;
    void setHeader(const std::string& key, const std::string& value);

    std::string getBody() const;
    void setBody(const std::string& body);
};

#endif
