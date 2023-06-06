#include <iostream>
#include "cipherlock.hpp"

int main() {
    int key = 3; // Choose a key value

    // Create an instance of the CipherLock class
    CipherLock cipherLock(key);

    // Get input from the user
    std::string message;
    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, message);

    // Encrypt the message
    std::string encrypted = cipherLock.encrypt(message);
    std::cout << "Encrypted message: " << encrypted << std::endl;

    // Decrypt the message
    std::string decrypted = cipherLock.decrypt(encrypted);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    return 0;
}
