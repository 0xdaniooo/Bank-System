#pragma once

#include "Account.h"

/*
    Written by Daniel Kasprzyk
*/

class SavingsAccount : public Account
{
    public:
        float interestRate;
        int years;

        SavingsAccount();
};