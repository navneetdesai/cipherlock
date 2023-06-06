#ifndef CIPHERLOCK_HPP
#define CIPHERLOCK_HPP

#include <string>

class CipherLock {
public:
    explicit CipherLock(int key);
    std::string encrypt(const std::string& message);
    std::string decrypt(const std::string& cipher);
    void set_key(int key);

private:
    int key;
};

#endif
