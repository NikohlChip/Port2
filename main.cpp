#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>

std::string bubbleSortNames();

class User{
    public:
        std::string f_name, l_name, status;
        int id, age;
        int genID(int range){
            srand(time(NULL));
            return rand() % range;
        }
        User(std::string f_name, std::string l_name){
            this->f_name = f_name;
            this->l_name = l_name;
            this->id = genID(10000);
        }
};

void listUsers(std::vector<User> users){
    std::cout << "ID\tFirst Name\tLast Name\n";
    for(int i=0; i<users.size();i++){
        std::cout << users[i].id << "\t" << users[i].f_name << "\t\t" << users[i].l_name << std::endl;
    }
}

int add_user_if_not_exists(std::vector<User> &users){
    std::string f_enter, l_enter;
    std::cout << "Enter first name: "; std::cin >> f_enter;
    std::cout << "Enter last name: "; std::cin >> l_enter;
    User newUser(f_enter,l_enter);

    for(int i=0; i<users.size();i++){
        if(users[i].f_name == newUser.f_name && users[i].l_name == newUser.l_name)
            std::cout << "Provided entry already exists, exiting" << std::endl;
    }
    users.push_back(newUser);
    return users.size() - 1;
}

int main(){
    int SELECTION;
    std::vector<User> users;
    
    do{
        std::cout << "---SELECT OPTION---\n1: List users(" << users.size() <<
        ") user(s)\n2: Add users\n3: Import user list\n4:Export user list\n0:Exit program\nAwaiting input--->";
        std::cin >> SELECTION;
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