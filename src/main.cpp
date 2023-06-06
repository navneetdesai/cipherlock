#include <iostream>
#include "cipherlock.hpp"
#include "UserManager.hpp"



/**
 * @brief Prints the features of the program
 *        and returns the option chosen by the user.
 * 
 * @return int 
 */
int print_features() {
    int option = -1;
    std::cout << "\n\nWelcome to Cipherlock!\n";
    do {
        std::cout << "Choose an option: \n";   
        std::cout << "1. Register user\n";
        std::cout << "2. Login user\n";
        std::cout << "3. List passwords\n";
        std::cout << "4. Remove user\n";
        std::cout << "5. Exit\n\n"; 
        std::cin >> option;
    } while (option < 1 || option > 5);
    return option;
}

/**
 * @brief Gets the cipher key from the user.
 * 
 * @return int 
 */
int get_cipher_key() {
    int key = -1;
    do {
        std::cout << "Enter cipher key (should be positive): ";
        std::cin >> key;
    } while (key < 0);
    return key;
}

/**
 * @brief Stores or retrieves a password based on user's choice.
 * 
 * @param manager 
 * @param cipherlock 
 * @param key 
 */
void store_or_retrieve(UserManager manager, CipherLock cipherlock, int key) {
    int option = -1;
    std::string username;
    std::string password;
    do {
        std::cout << "1. Store password\n";
        std::cout << "2. Retrieve password\n";
        std::cout << "3. Exit\n";
        std::cin >> option;
    } while (option < 1 || option > 3);
    switch (option) {
    case 1:
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        manager.store_password(username, cipherlock.encrypt(password));
        break;
    case 2:
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Your password is: " << cipherlock.decrypt(manager.list_passwords(username)[0]) << std::endl;
        break;
    case 3:
        break;
    default:
        break;
    }
}


/**
 * @brief Use cipherlock based on user's choice
 *        
 * @param option 
 */
void use_cipherlock(UserManager manager, CipherLock cipherlock, int option, int key) {

    std::string username;
    std::string password;
    switch (option) {
    case 1:
        std::cout << "Enter username for registration: " << std::endl;
        std::cin >> username;
        std::cout << "Enter password for registration: " << std::endl;
        std::cin >> password;
        if (manager.register_user(username, password)) {
            std::cout << "User registered successfully!" << std::endl;
        } else {
            std::cout << "User registration failed!" << std::endl;
        }
        break;
    case 2:
        std::cout << "Enter username for login: " << std::endl;
        std::cin >> username;
        std::cout << "Enter password for login: " << std::endl;
        std::cin >> password;
        if (manager.login_user(username, password)) {
            std::cout << "User logged in successfully!" << std::endl;
            store_or_retrieve(manager, cipherlock, key);
        } else {
            std::cout << "User login failed!" << std::endl;
        }
        break;
    }
}


/**
 * @brief Main function of the program.
 * 
 * @return int 
 */
int main() {
    int option;
    CipherLock cipherlock(0);
    while (true) {
        option = print_features();
        if (option == 5) {
            break;
        }
        int key = get_cipher_key();
        cipherlock.set_key(key);
        UserManager manager("users.txt");
        use_cipherlock(manager, cipherlock, option, key);
    }

    return 0;
}
