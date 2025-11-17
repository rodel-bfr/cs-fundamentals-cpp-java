public class BankAccount {

    private double balance;       // Stores the current account balance
    private double totalPayments; // Tracks the total sum of payments made

    // Class constructor
    public BankAccount(double initialBalance) {
        // 'this' is used to refer to the current object being constructed
        this.balance = initialBalance;     // Initializes balance with the provided amount
        this.totalPayments = 0.0;          // Initializes total payments to zero
    }

    // Class methods
    public void makePayment(double paymentAmount) {
        // Checks if the balance is greater than or equal to the payment amount
        if (balance >= paymentAmount) {
            balance -= paymentAmount;        // Deducts the payment amount from the balance
            totalPayments += paymentAmount;  // Adds the payment amount to total payments
            // Print confirmation and new balance
            System.out.println("Payment of " + paymentAmount + " processed. New balance: " + balance);
        } else {    // Otherwise, print an insufficient funds message and the current balance
            System.out.println("Insufficient funds to make payment of " + paymentAmount);
            System.out.println("Current balance: " + balance);
        }
    }

    public double getBalance() {
        // Prints the current balance to the console
        System.out.println("Current balance: " + balance);
        return balance; // Returns the current balance
    }

    public double getTotalPayments() {
        // Prints the total payments after all transactions
        System.out.println("Total payments made: " + totalPayments);
        return totalPayments; // Returns the total payments
    }
}