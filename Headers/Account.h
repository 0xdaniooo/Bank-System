#pragma once

#include <iostream>
#include <string>

/*
    Written by Daniel Kasprzyk
*/

class Account
{
    public:
        std::string accountName;

        float balance = 0.00f;
        std::string accountID;      //16 characters
        std::string sortCode;       //6 characters
        std::string accountNumber;  //8 characters
        std::string CVV;            //3 characters

    public:
        Account();
        void GenerateDetails();
};