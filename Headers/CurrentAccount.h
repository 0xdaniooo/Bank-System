#pragma once

#include "Account.h"

/*
    Written by Daniel Kasprzyk
*/

class CurrentAccount : public Account
{
    public:
        using Account::Account;
        CurrentAccount();
};