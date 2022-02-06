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
        showMenu(users);
        std::cin >> SELECTION;
        std::cout << "\n";

        switch (SELECTION){
            case 1:
                listUsers(users);
                break;
            case 2:
                add_user_if_not_exists(users);
                break;
            case 3:
                importFile(users);
                break;
            case 4:
                exportFile(users);
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