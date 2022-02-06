#ifndef HEADER_H
#define HEADER_H

class User{
    private:
        int genID(int range);
    public:
        std::string f_name, l_name, status;
        int id, age;
        User(std::string f_name, std::string l_name);
        User(int id, std::string f_name, std::string l_name);
};

std::string bubbleSortNames();
void showMenu(std::vector<User> users);
void importFile(std::vector<User> &users);
void exportFile(std::vector<User> users);
void listUsers(std::vector<User> users);
int add_user_if_not_exists(std::vector<User> &users);

#endif