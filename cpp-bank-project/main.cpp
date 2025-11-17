#include <iostream>
#include <string>   // Needed for the prompt message
#include <limits>   // Needed for cin.ignore

using namespace std;

// Structure for defining the bank account
struct Account {
    double balance;
    double interest_rate;
    double credit_limit;
};

/**
 * A professional, reusable function to get a valid double.
 * It checks for data type (no letters) and logical errors (no negative numbers).
 */
double getValidPositiveDouble(string prompt) {
    double value;
    cout << prompt;
    // Loop continues if cin fails (wrong type) OR if the value is negative
    while (!(cin >> value) || value < 0) {
        cout << "Error: Please enter a valid positive number: ";
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush the buffer
    }
    return value;
}

/**
 * A professional, reusable function to get a valid integer.
 * It checks for data type (no letters) and logical errors (number must be > 0).
 */
int getValidPositiveInt(string prompt) {
    int value;
    cout << prompt;
    // Loop continues if cin fails (wrong type) OR if the value is zero or less
    while (!(cin >> value) || value <= 0) {
        cout << "Error: Please enter a valid positive integer: ";
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush the buffer
    }
    return value;
}


int main() {
    // Bank account variables
    Account bank_account;
    double initial_balance, interest_rate, credit_limit, payment_amount, partial_balance,
        partial_credit_payment, interest_applied;
    int num_months;

    // --- INPUT SECTION ---
    // Get all user inputs using the new robust functions
    initial_balance = getValidPositiveDouble("Initial account balance: ");
    interest_rate = getValidPositiveDouble("Enter the interest rate (%): ");
    credit_limit = getValidPositiveDouble("Enter the credit limit: ");

    // Initialize the bank account
    bank_account.balance = initial_balance;
    bank_account.interest_rate = interest_rate;
    bank_account.credit_limit = credit_limit;

    // Set up recurring payments
    payment_amount = getValidPositiveDouble("Enter the recurring payment amount: ");
    num_months = getValidPositiveInt("Enter the number of months for payment: ");
    cout << endl;
    
    // --- PROCESSING SECTION ---

    // Process recurring payments
    for (int month = 1; month <= num_months; ++month) {
        // Display the current month
        cout << "Month " << month << ":" << endl;
        cout << "---------------------------------------" << endl;

        // Check for available funds (balance + credit)
        if (bank_account.balance + bank_account.credit_limit < payment_amount) {
            // Display insufficient funds message and remaining credit
            cout << "Insufficient funds! Payment cannot be processed." << endl;
            cout << "Remaining credit limit: " << bank_account.credit_limit << endl;
            break; // Stop the program if funds are insufficient
        }

        // Process monthly payment
        // Check if the balance is sufficient for the payment
        if (bank_account.balance >= payment_amount) {
            bank_account.balance -= payment_amount;
            cout << "Payment of " << payment_amount << " processed from current balance."
                 << endl;
        } else {
            // Case: Insufficient balance - Use credit limit
            partial_balance =
                bank_account.balance; // Save the partial amount from the balance
            partial_credit_payment =
                payment_amount -
                bank_account.balance; // Calculate the remainder to be paid from credit
            bank_account.balance = 0; // Set balance to zero
            bank_account.credit_limit -=
                partial_credit_payment; // Deduct the remainder from credit limit

            // Display message about partial payment
            cout << "Insufficient balance!" << endl;
            cout << "Using " << partial_balance << " from balance and "
                 << partial_credit_payment << " from credit limit." << endl;
        }

        // Display balance before applying interest
        cout << "Balance before interest: " << bank_account.balance
             << endl;

        // Apply monthly interest
        interest_applied = bank_account.balance * bank_account.interest_rate / 100;
        bank_account.balance += interest_applied;

        // Display account status
        cout << "Interest applied: " << interest_applied << " ("
             << bank_account.interest_rate << "%)" << endl;
        cout << "New balance: " << bank_account.balance << endl;
        cout << "Balance at end of month " << month << ": " << bank_account.balance
             << endl;
        cout << "Remaining credit limit: " << bank_account.credit_limit << endl;
        cout << "---------------------------------------" << endl << endl;
    }

    // Display final account balance
    cout << "Final account balance: " << bank_account.balance << endl;

    // --- PROGRAM PAUSE SECTION ---
    cout << "\nPress Enter to exit..." << endl; // \n adds a new line for spacing
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears any leftover input
    cin.get(); // Waits for the user to press Enter
    // -----------------------

    return 0;
}