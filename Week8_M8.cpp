// Module 8: Bank Account Simulation
// In this program, I'm practicing class design and file I/O.
// I made a simple BankAccount class that can do deposits, purchases,
// print the balance, and save each action to a file called transactions.txt.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// BankAccount class
class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount(double initialBalance = 0.0) {
        balance = initialBalance;
    }

    // Deposit money into the account
    void deposit(double amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
        cout << "Deposited: $" << amount << endl;
    }

    // Make a purchase(from balance)
    void purchase(double amount) {
        if (amount <= balance) {
            balance -= amount;
            saveTransaction("Purchase", amount);
            cout << "Purchase made: $" << amount << endl;
        } else {
            cout << "Not enough money for this purchase.\n";
        }
    }

    // Print current balance
    void printBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    // Save transaction to file 
    void saveTransaction(string type, double amount) {
        ofstream out("transactions.txt", ios::app); // append so we don't overwrite
        if (out.is_open()) {
            out << type << ": $" << amount << " | New Balance: $" << balance << endl;
            out.close();
        } else {
            cout << "Error opening transactions.txt\n";
        }
    }
};

int main() {

    //   Make Banka ccount object
    BankAccount myAccount;

    // Firrst deposit
    cout << "Adding initial deposit...\n";
    myAccount.deposit(150.00);

    // Two purchases
    cout << "\nMaking two purchases...\n";
    myAccount.purchase(40.50);
    myAccount.purchase(20.25);

    // Print final balance
    cout << "\nFinal Balance:\n";
    myAccount.printBalance();

    cout << "\nAll actions saved to transactions.txt\n";

    return 0;
}
/*M8.cpp -o Week6_M8 && "/Users/sefanit/Desktop/CIS 25/"Week6_M8
Adding initial deposit...
Deposited: $150

Making two purchases...
Purchase made: $40.5
Purchase made: $20.25

Final Balance:
Current Balance: $89.25

All actions saved to transactions.txt
sefanit@Sefanit
*/