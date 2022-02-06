#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include "header.h"

int User::genID(int range){
        srand(time(NULL));
        return rand() % range;
}

User::User(std::string f_name, std::string l_name){
            this->f_name = f_name;
            this->l_name = l_name;
            this->id = genID(10000);
        }

void listUsers(std::vector<User> users){
    std::cout << "ID\tFirst Name\tLast Name\n---------------------------------\n";
    for(int i=0; i<users.size();i++){
        std::cout << users[i].id << "\t" << users[i].f_name << "\t\t" << users[i].l_name << std::endl;
    }
}

int add_user_if_not_exists(std::vector<User> &users){
    std::string f_enter, l_enter;
    std::cout << "Enter Forename: "; std::cin >> f_enter;
    std::cout << "Enter Surname: "; std::cin >> l_enter;
    User newUser(f_enter,l_enter);

    for(int i=0; i<users.size();i++){
        if(users[i].f_name == newUser.f_name && users[i].l_name == newUser.l_name)
            std::cout << "Provided entry already exists, exiting" << std::endl;
    }
    users.push_back(newUser);
    return users.size() - 1;
}