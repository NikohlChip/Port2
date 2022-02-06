#ifndef HEADER_H
#define HEADER_H

class User{
    public:
        std::string f_name, l_name, status;
        int id, age;
        int genID(int range);
        User(std::string f_name, std::string l_name);
};

std::string bubbleSortNames();
void listUsers(std::vector<User> users);
int add_user_if_not_exists(std::vector<User> &users);

#endif