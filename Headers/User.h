#pragma once

#include <string>
#include <vector>

#include "Account.h"

/*
    Written by Daniel Kasprzyk
*/

class User
{
    public:
        std::string firstName;
        std::string lastName;

        std::string emailAddress;
        std::string password;

        std::vector<Account> accounts;

        User(std::string fName, std::string lName, std::string email, std::string pass);
};