#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin {
private:
    std::string username;
    std::string password;

    void addFlight();
    void viewFlights();
    void deleteFlight();

public:
    bool login();
    bool signup();
    void showMenu();
};

#endif
