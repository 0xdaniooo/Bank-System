#include "Account.h"

/*
    Written by Daniel Kasprzyk
*/

Account::Account()
{
    GenerateDetails();
}

// Randomly generate bank account details
void Account::GenerateDetails()
{
    int index = 0;
    int numbers[33];

    int max = 9;
    srand(time(NULL));

    std::string currentString;

    //Generate random numbers
    for (int i = 0; i < 33; i++)
    {
        numbers[i] = rand() % max;
    }

    //Populate account ID
    for (index = 0; index < 16; index++)
    {
        currentString = std::__cxx11::to_string(numbers[index]);
        accountID += currentString;
    }

    //Populate sort code
    for (index; index < 22; index++)
    {
        currentString = std::__cxx11::to_string(numbers[index]);
        sortCode += currentString;
    }

    //Populate account number
    for (index; index < 30; index++)
    {
        currentString = std::__cxx11::to_string(numbers[index]);
        accountNumber += currentString;
    }

    //Populate CVV
    for (index; index < 33; index++)
    {
        currentString = std::__cxx11::to_string(numbers[index]);
        CVV += currentString;
    }
}
