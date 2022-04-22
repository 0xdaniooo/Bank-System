#include <iostream>
#include <iomanip>
#include <string>

#include "Bank.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Database.h"

using std::cout, std::cin; 
using std::endl, std::string;

/*
    Written by Daniel Kasprzyk
*/

// Initialize the bank program
Bank::Bank()
{
    database = new Database();
    
    Welcome();
}

// Home page
void Bank::Welcome()
{
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Welcome To MyBank" << endl;
    cout << "" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
            {
                LoginUser();
                break;
            }

            case 2:
            {
                SignUpUser();
                break;
            }

            case 3:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Create new user
void Bank::SignUpUser()
{
    ClearDisplay();

    string firstName, lastName, email, pass1, pass2;

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Please enter your details to create your account" << endl;
    cout << "" << endl;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Email Address: ";
    cin >> email;

    while (!actionCompleted)
    {
        cout << "Password: ";
        cin >> pass1;

        cout << "Repeat Password: ";
        cin >> pass2;
    
        if (pass1 != pass2)
        {
            cout << "Passwords don't match. Please try again" << endl;
            continue;
        }

        actionCompleted = true;
    }

    currentUser = new User(firstName, lastName, email, pass2);

    database->users.push_back(currentUser);

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Signed Up Succesfully!" << endl;
    cout << "" << endl;
    cout << "1. Open New Account" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1: 
            {
                CreateAccount();
                break;
            }

            case 2:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Login to already existing user
void Bank::LoginUser()
{
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Login" << endl;
    cout << "" << endl;

    string email, password;

    while (!actionCompleted)
    {
        cout << "Email Address: ";
        cin >> email;

        cout << "Password: ";
        cin >> password;

       for (int i = 0; i < database->users.size(); i++)
       {
           if (database->users.at(i)->emailAddress == email)
           {
               if (database->users.at(i)->password == password)
                {
                    actionCompleted = true;
                    currentUser = database->users.at(i);
                    break;
                }
           }

           cout << "Login details not found. Please try again." << endl;
           cout << endl;
       }
    }

    MainMenu();
}

// Logout the current user
void Bank::LogoutUser()
{
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Log Out?" << endl;
    cout << "" << endl;
    cout << "1. Yes (Log Out)" << endl;
    cout << "2. No (Go Back)" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
            {
                currentUser = NULL;
                Welcome();
                break;
            }

            case 2:
            {
                MainMenu();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Create new bank account
void Bank::CreateAccount()
{
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Account Type" << endl;
    cout << "" << endl;

    while (!actionCompleted)
    {
        cout << "1. Current Account" << endl;
        cout << "2. Savings Account" << endl;
        cout << "" << endl;

        cout << "Account to create: ";
        Input();

        switch (choice)
        {
            case 1:
            {
                account = new CurrentAccount();
                actionCompleted = true;
                break;
            }

            case 2:
            {
                account = new SavingsAccount();
                actionCompleted = true;
                break;
            }

            default: 
            {
                cout << "" << endl;
                cout << "Unrecognized input. Please try again." << endl;;
                cout << "" << endl;
            }
        }
    }

    currentUser->accounts.push_back(*account);

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Account Created Succesfully!" << endl;
    cout << "" << endl;
    cout << "1. Go To Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1: 
            {
                MainMenu();
                break;
            }

            case 2:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Display all options
void Bank::MainMenu()
{
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "MyBank Main Menu" << endl;
    cout << "" << endl;
    cout << "1. View Account Details" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Transfer Money" << endl;
    cout << "4. Create New Account" << endl;
    cout << "5. Delete Account" << endl;
    cout << "6. Logout" << endl;
    cout << "7. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
                AccountDetails();
                break;
            
            case 2:
                DepositMoney();
                break;

            case 3:
                TransferMoney();
                break;
            
            case 4:
                CreateAccount();
                break;

            case 5:
                DeleteAccount();
                break;

            case 6:
                LogoutUser();
                break;

            case 7:
                Exit();
                break;

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Display all account details
void Bank::AccountDetails()
{
    if (currentUser->accounts.size() > 1)
    {
        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;

        while (!actionCompleted)
        {
            for (int i = 0; i < currentUser->accounts.size(); i++)
            {
                int id = i;
                id++;

                cout << id;
                cout << ". ";
                cout << currentUser->accounts.at(i).accountName;
                cout << " $";
                cout << currentUser->accounts.at(i).balance << endl;
            }

            cout << "Account To Display: " << endl;
            Input();

            choice -= 1;

            if (choice > currentUser->accounts.size() - 1)
            {
                cout << "Incorrect option. Please try again" << endl;
                continue;
            }

            actionCompleted = true;
        }
    }

    else 
    {
        choice = 0;
    }

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Bank Account Details" << endl;
    cout << "" << endl;
    cout << "--" + currentUser->accounts.at(choice).accountName + "--" << endl;
    cout << "Name: " + currentUser->firstName + " " + currentUser->lastName << endl;
    
    cout << "Balance: $";
    cout << std::setprecision(2) << std::fixed << currentUser->accounts.at(choice).balance << endl;
    
    cout << "" << endl;
    
    cout << "Account ID: ";
    StringFormatter(currentUser->accounts.at(choice).accountID, 4, false);

    cout << "Account Number: " + currentUser->accounts.at(choice).accountNumber << endl;
    
    cout << "Sort Code: ";
    StringFormatter(currentUser->accounts.at(choice).sortCode, 3, true);

    cout << "CVV: " + currentUser->accounts.at(choice).CVV << endl;
    
    cout << "" << endl;
    cout << "1. Go To Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    while (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
                MainMenu();
                break;
            
            case 2:
                Exit();
                break;

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Transfer money between personal accounts or users accounts
void Bank::TransferMoney()
{
    ClearDisplay();

    string accountN, transferAmount;

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Transfer Money" << endl;
    cout << "" << endl;
    cout << "1. Transfer Money To Someone" << endl;
    cout << "2. Transfer Money Between Personal Accounts" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    Input();

    accountToShow = 0;
    int accountFrom = 0, accountToMoveTo;

    if (currentUser->accounts.size() > 1 && choice == 2)
    {
        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;
        
        bool accountChosen = false;

        while (!accountChosen)
        {
            for (int i = 0; i < currentUser->accounts.size(); i++)
            {
                int id = i;
                id++;
                
                cout << id;
                cout << ". Account - Balance: $";
                cout << currentUser->accounts.at(i).balance << endl;
            }

            cout << "Account To Transfer From: " << endl;
            cin >> choice;

            accountToShow = choice -= 1;

            if (accountToShow > currentUser->accounts.size() - 1)
            {
                cout << "Incorrect option. Please try again" << endl;
                continue;
            }

            accountChosen = true;
            accountFrom = accountToShow;
        }
    }

    //accountToShow = 0;

    //if (currentUser->accounts.size() > 1)
    //{
    else if (choice == 1)
    {
        ClearDisplay();

        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;
        
        bool accountChosen = false;

        while (!accountChosen)
        {
            if (choice == 1)
            {
                string fName, lName;

                cout << "Enter first name of recipient: ";
                cin >> fName;

                cout << "Enter last name of recipient: ";
                cin >> lName;

                for (int i = 0; i < database->users.size(); i++)
                {
                    if (database->users.at(i)->firstName == fName)
                    {
                        if (database->users.at(i)->lastName == lName)
                        {
                            accountChosen = true;
                            otherUser = database->users.at(i);
                            break;
                        }
                    }
                }
                
                cout << "Login details not found. Please try again." << endl;
            }

            else if (choice == 2 && currentUser->accounts.size() > 1)
            {
                for (int i = 0; i < currentUser->accounts.size(); i++)
                {
                    if (i == accountFrom)
                    {
                        continue;
                    }
                    
                    int id = i;
                    id++;

                    cout << id;
                    cout << ". Account - Balance: $";
                    cout << currentUser->accounts.at(i).balance << endl;
                }

                cout << "Account To Transfer To: " << endl;
                cin >> choice;

                accountToShow = choice -= 1;

                if (accountToShow > currentUser->accounts.size() - 1)
                {
                    cout << "Incorrect option. Please try again" << endl;
                    continue;
                }

                accountChosen = true;
                accountToMoveTo = accountToShow;
            }
        }
    }

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Transfer Money" << endl;
    cout << "" << endl;

    bool transferComplete = false;
    
    while (!transferComplete)
    {
        cout << "Transfer Amount: $";
        cin >> transferAmount;

        float transferMoney = stof(transferAmount);

        if (currentUser->accounts.at(accountFrom).balance < transferMoney)
        {
            cout << "Insufficient funds in account. Please try again." << endl;
            continue;
        }

        if (choice == 2)
        {
            currentUser->accounts.at(accountToMoveTo).balance += transferMoney;
            currentUser->accounts.at(accountFrom).balance -= transferMoney;
        }

        else if (choice == 1)
        {
            currentUser->accounts.at(accountToMoveTo).balance -= transferMoney;
            otherUser->accounts.at(0).balance += transferMoney;
        }
        
        transferComplete = true;
    }

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Money Transferred Succesfully!" << endl;
    cout << "" << endl;
    cout << "1. Go To Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    if (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
            {
                MainMenu();
                break;
            }

            case 2:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Deposit money to account
void Bank::DepositMoney()
{
    ClearDisplay();

    accountToShow = 0;

    if (currentUser->accounts.size() > 1)
    {
        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;
        
        bool accountChosen = false;

        while (!accountChosen)
        {
            for (int i = 0; i < currentUser->accounts.size(); i++)
            {
                int id = i;
                id++;
                cout << id;
                cout << ". Account - Balance: $";
                cout << currentUser->accounts.at(i).balance << endl;
            }

            cout << "Account To Deposit Into: " << endl;
            Input();

            accountToShow = choice -= 1;

            if (accountToShow > currentUser->accounts.size() - 1)
            {
                cout << "Incorrect option. Please try again" << endl;
                continue;
            }

            accountChosen = true;
        }
    }

    string moneyToDeposit;

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Deposit Money" << endl;
    cout << "" << endl;
    cout << "Choose amount to deposit: $";

    cin >> moneyToDeposit;
    float convertedMoney = std::stof(moneyToDeposit);
    currentUser->accounts.at(accountToShow).balance += convertedMoney;

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Money Deposited Succesfully!" << endl;
    cout << "" << endl;
    cout << "1. Go To Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    if (!actionCompleted)
    {
        Input();

        switch (choice)
        {
            case 1:
            {
                MainMenu();
                break;
            }

            case 2:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Delete bank account
void Bank::DeleteAccount()
{
    ClearDisplay();

    accountToShow = 0;
    int accountToDelete, accountToMoveTo;

    if (currentUser->accounts.size() > 1)
    {
        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;
        
        bool accountChosen = false;

        while (!accountChosen)
        {
            for (int i = 0; i < currentUser->accounts.size(); i++)
            {
                int id = i;
                id++;

                cout << id;
                cout << ". Account - Balance: $";
                cout << currentUser->accounts.at(i).balance << endl;
            }

            cout << "Account To Be Deleted: " << endl;
            cin >> choice;

            accountToShow = choice -= 1;

            if (accountToShow > currentUser->accounts.size() - 1)
            {
                cout << "Incorrect option. Please try again" << endl;
                continue;
            }

            accountChosen = true;
            accountToDelete = accountToShow;
        }
    }

    accountToShow = 0;

    ClearDisplay();

    if (currentUser->accounts.size() > 1)
    {
        cout << "======================================================" << endl;
        cout << "" << endl;
        cout << "Choose Account" << endl;
        cout << "" << endl;
        
        bool accountChosen = false;

        while (!accountChosen)
        {
            for (int i = 0; i < currentUser->accounts.size(); i++)
            {
                int id = i;
                id++;

                cout << id;
                cout << ". Account - Balance: $";
                cout << currentUser->accounts.at(i).balance << endl;
            }

            cout << "Account To Move Money Into: " << endl;
            cin >> choice;

            accountToShow = choice -= 1;

            if (accountToShow > currentUser->accounts.size() - 1)
            {
                cout << "Incorrect option. Please try again" << endl;
                continue;
            }

            accountChosen = true;
            accountToMoveTo = accountToShow;
        }
    }
    
    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Delete Account Permanently" << endl;
    cout << "" << endl;
    cout << "1. Yes (Action Cannot Be Reversed)" << endl;
    cout << "2. No (Back to menu)" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    Input();

    switch (choice)
    {
        case 1:
        {
            currentUser->accounts.at(accountToMoveTo).balance += currentUser->accounts.at(accountToDelete).balance;
            currentUser->accounts.erase(currentUser->accounts.begin() + accountToDelete);
            break;
        }

        case 2:
        {
            MainMenu();
            break;
        }

        default: cout << "Unrecognized input. Please try again: ";
    }

    ClearDisplay();

    cout << "======================================================" << endl;
    cout << "" << endl;
    cout << "Account Deleted Successfully!" << endl;
    cout << "" << endl;
    cout << "1. Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "" << endl;
    cout << "Please choose one of these options: ";

    if (!actionCompleted)
    {
        switch (choice)
        {
            case 1:
            {
                MainMenu();
                break;
            }

            case 2:
            {
                Exit();
                break;
            }

            default: cout << "Unrecognized input. Please try again: ";
        }
    }
}

// Exit the program
void Bank::Exit()
{
    cout << "Exiting..." << endl;
    exit(0);
}

// Take input from the user
void Bank::Input()
{
    cin >> choice;
}

// Prepare display for new interaction
void Bank::ClearDisplay()
{
    system("cls");
    actionCompleted = false;
}

// Used to split string into parts
void Bank::StringFormatter(string stringToParse, int divider, bool dashes)
{
    string completeString;
    int stringLength = stringToParse.size();

    //Error state
    if (stringLength % divider != 0) 
    {
        return;
    }

    //Calculate how many characters to print at a time
    int partSize = stringLength / divider;

    for (int i = 0; i < stringLength; i++) 
    {
        //Happens when string division reached eg divide by 2 would stop after 2 characters
        if (i != 0 && i % partSize == 0) 
        {
            if (dashes)
            {
                completeString += "-";
            }

            else
            {
                completeString += " ";
            }
        }

        completeString += stringToParse[i];
    }

    cout << completeString << endl;
}