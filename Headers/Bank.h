#pragma once

#include <vector>

#include "Account.h"
#include "User.h"
#include "Database.h"

/*
    Written by Daniel Kasprzyk
*/

class Bank
{
    public:
        int choice;
        int accountToShow;
        bool actionCompleted;
        Account* account;
        User* currentUser;
        User* otherUser;

        Database* database;

        Bank();
        void Welcome();
        void SignUpUser();
        void LoginUser();
        void LogoutUser();
        void CreateAccount();
        void MainMenu();
        void AccountDetails();
        void TransferMoney();
        void DepositMoney();
        void DeleteAccount();
        void Exit();
        void Input();
        void ClearDisplay();
        void StringFormatter(std::string stringToParse, int divider, bool dashes);
};