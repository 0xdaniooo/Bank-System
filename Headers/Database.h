#pragma once

#include <vector>

#include "User.h"

/*
    Written by Daniel Kasprzyk
*/

class Database
{
    public:
        std::vector<User*> users;

        Database();
};