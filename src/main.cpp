/*
 * Copyright (c) 2023 Navneet Desai
 */

#include <iostream>
#include "user.hpp"
#include "user_manager.hpp"
using namespace std;

int main() {
    UserManager userManager;

    // Register a new user
    userManager.registerUser("john_doe", "password123", "john.doe@example.com");
    cout << "Registered a new user!" << endl;


    return 0;
}
