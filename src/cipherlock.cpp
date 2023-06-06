#include "cipherlock.hpp"
#include <iostream>

CipherLock::CipherLock() {
    key = 0;
}
CipherLock::CipherLock(int key) : key(key) {}

std::string CipherLock::encrypt(const std::string& message)  {
    std::string encrypted;
    for (char c : message) {
        // Encrypt the character using the key
        char encryptedChar = c + key;
        encrypted.push_back(encryptedChar);
    }
    return encrypted;
}


std::string CipherLock::decrypt(const std::string& cipher) {
    std::string decrypted;
    for (char c : cipher) {
        // Decrypt the character using the key
        char decryptedChar = c - key;
        decrypted += decryptedChar;
    }
    return decrypted;
}

void CipherLock::set_key(int key) {
    this->key = key;
}
