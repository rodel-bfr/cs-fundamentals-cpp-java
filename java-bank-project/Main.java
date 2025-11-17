public class Main {
    public static void main(String[] args) {
        // Run the BankAccount class constructor with 1000.0 (initial balance)
        BankAccount account = new BankAccount(1000.0);

        // Call methods of the BankAccount class
        // Print the initial balance to the console
        account.getBalance();

        // Call the makePayment method with different parameters
        account.makePayment(300.0);
        account.makePayment(150.0);
        account.makePayment(200.0);
        account.makePayment(500.0); // This one will fail

        // Print the total payments after all transactions
        account.getTotalPayments();
    }
}