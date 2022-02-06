#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>
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

User::User(int id, std::string f_name, std::string l_name){
            this->f_name = f_name;
            this->l_name = l_name;
            this->id = id;
}

void showMenu(std::vector<User> users){
    std::cout << "---SELECT OPTION---\n1: List users - currently " <<
        users.size() << " user(s)\n2: Add new entry\n3: Import user list\n" <<
        "4: Export user list\n5: Calculate Pi\n0: Exit program\n\nAwaiting input--->";
}

void importFile(std::vector<User> &users){
    std::ifstream file ("config.txt", std::ios::in);
    int id;
    std::string f_name, l_name;

    while(file >> id >> f_name >> l_name){
        User newUser(id, f_name, l_name);
        std::cout << newUser.f_name << " " << newUser.l_name << "(#" <<
        newUser.id << "), ";
        users.push_back(newUser);
    }
    std::cout << std::endl;
}

void exportFile(std::vector<User> users){
    std::string filename;
    filename = "config.txt";
    std::ofstream file;
    file.open(filename, std::ofstream::out);

    for(int i=0; i<users.size(); i++){
        file << users[i].id << "\t" << users[i].f_name << "\t" << users[i].l_name << std::endl;
    }

    if(file.is_open())
        std::cout << "Export successful\n" << std::endl;
}

std::string bubbleSortNames();

void listUsers(std::vector<User> users){
    std::cout << "ID\tFirst Name\tLast Name\n---------------------------------\n";
    for(int i=0; i<users.size();i++){
        std::cout << users[i].id << "\t" << users[i].f_name 
        << "\t\t" << users[i].l_name << std::endl;
    }
    std::cout << std::endl;
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

void calculatePi(){
    int sampleSize;

    std::cout << "EXPLANATION\n" << "This program will calculate a rather accurate value of Pi using the Monte Carlo method." << 
    std::endl << "Upon calculation, you will be prompted to enter a value determining the total sample size for the calculation.\n";
    std::cout << "Set sample size (this will begin the calculation!): ";
    std::cin >> sampleSize;

    srand(time(NULL));
    std::vector<double> x,y,res;
    double sum, resultingPi;
    int inCircle;

    for(int i=0; i<sampleSize; i++){
        x.push_back((double)rand()/RAND_MAX);
        y.push_back((double)rand()/RAND_MAX);
        res.push_back(sqrt(pow(x[i],2) + pow(y[i],2)));
        if(res[i]<=1.0) inCircle++;
        
        std::cout << "\rIteration: " << i+1 << "    Current Pi: " << 4.0*inCircle/(i+1) <<
        "    Progress: " <<(double)i*100/(double)sampleSize << "%" <<
        std::flush;
    }

    resultingPi = 4.0 * inCircle / sampleSize;
    std::cout << "\nCalculation complete.\n" <<
    "\nSample size:\t" << sampleSize+1 << 
    "\nIn circle*4:\t" << 4*inCircle <<
    "\nCalculated Pi:\t" << resultingPi << "\n\n";
}