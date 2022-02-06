#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include "header.h"

int main(){
    int SELECTION;
    std::vector<User> users;
    
    do{
        std::cout << "---SELECT OPTION---\n1: List users(" << users.size() <<
        ") user(s)\n2: Add users\n3: Import user list\n4: Export user list\n0: Exit program\n\nAwaiting input--->";
        std::cin >> SELECTION;
        std::cout << "\n";

        switch (SELECTION){
            case 1:
                listUsers(users);
                break;
            case 2:
                add_user_if_not_exists(users);
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid input" << std::endl;
        }
    }
    while(SELECTION);

    return 0;
}