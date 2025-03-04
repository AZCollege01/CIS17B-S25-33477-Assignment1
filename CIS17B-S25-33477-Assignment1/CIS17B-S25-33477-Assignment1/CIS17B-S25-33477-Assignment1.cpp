// CIS17B-S25-33477-Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Aaron Zamora

//including header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// class BankAccount to handle functions of a Bank Acocunt
class BankAccount {
    private:
        string accountHolderName;
        int accountNumber;
        double balance;
    public:
        BankAccount() { // default constructor
            accountHolderName = "Null";
            balance = 0;
        }
		BankAccount(string accountname, double initDeposit) { // constructor to handle account creation
			accountHolderName = accountname;
			balance = initDeposit;
		}
        void deposit(double amount) { // function to handle depositing money
			balance += amount;
        }
        void withdraw(double amount) { // function to handle withdrawing money
            balance -= amount;
        }
        double getBalance() { // returns the balance of the account
			return balance;
        }
};

//start of the program
int main()
{
    //declaring variables
    string _accountName; // stores user input for account name
    double _initDeposit; // stores user input for initial deposit
    double depositAmount; // stores user input for deposit amount
    double withdrawAmount; // store user input for withdraw amount
    int choice; // stores user input for menu choice
    BankAccount* userAccount = nullptr; // creates a pointer for userAccount and set to nullptr

    // while loop to allow the user to continue using the menu and program.
    while (true) {
        //menu user interface
        cout << "Welcome to the banking system! Please enter number to select." << endl;
        cout << "1. Create an account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit the program." << endl;

        cin >> choice; //user input for menu choice

        switch (choice) {
        case 1: // account creation.
            if (userAccount != nullptr) { // checking if account already exists
                cout << "account already exists and in use." << endl;
            }
            else { //user inputs data for account
                cout << "Enter your account name: ";
                cin >> _accountName;
                cout << "Enter initial deposit: ";
                cin >> _initDeposit;
                userAccount = new BankAccount(_accountName, _initDeposit);
            }
            break;
        case 2: // deposit money
            if (userAccount != nullptr) { // checking if account exists before using deposit function
                cout << "enter amount to deposit: ";
                cin >> depositAmount;
                userAccount->deposit(depositAmount);
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 3: // withdraw money
            if (userAccount != nullptr) { // checking if account exists before using withdraw function
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                if (withdrawAmount > userAccount->getBalance()) // checks amount user inputed against account balance
                    cout << "Not enough balance." << endl;
                else {
                    userAccount->withdraw(withdrawAmount);
                }
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 4: // check balance
            if (userAccount != nullptr) { // checking if account exists before returning balance
                cout << fixed << showpoint << setprecision(2);
                cout << "Your balance is: " << userAccount->getBalance() << endl;
            }
            else {
                cout << "plese create an account first." << endl;
            }
            break;
        case 5: // exit program
            cout << "Exiting the program. Thanks for using the banking system!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select from 1 - 5." << endl;
            break;
        }
        if (choice == 5) { // breaks out of while loop if user enters 5
            break;
        }
    }
    //deleting userAccount object if it was created during the use of the program
    if (userAccount != nullptr) {
        delete userAccount;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
