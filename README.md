# Foundational Programming Projects (C++ & Java)

This repository contains two small foundational console applications built in **C++** and **Java**.

The goal of these projects was not to build full-scale applications, but to demonstrate a strong understanding of core computer science principles, including **data structures**, **Object-Oriented Programming (OOP)**, and **robust user input validation**.

For my larger, full-stack portfolio projects, please see the pinned repositories on my main GitHub profile.

---

## ✨ Key Features

### 1. C++ Bank Account Simulator

A command-line application that simulates a bank account with a credit limit. The program takes an initial balance, interest rate, and credit limit, then processes recurring monthly payments over a set number of months.

#### Features

* **Robust Input Validation:** The application will not crash on invalid user input (e.g., letters instead of numbers). It uses validation loops to ensure all inputs are the correct data type and within logical bounds (e.g., positive numbers).
* **Credit Limit Logic:** Correctly handles payments when the main balance is insufficient, using the available credit limit.
* **Monthly Interest:** Calculates and applies interest to the remaining balance at the end of each month.

### 2. Java Bank Account (OOP Demo)

A simple Java console application built to demonstrate core Object-Oriented Programming (OOP) principles.

#### Features

* **Object-Oriented Design (Java):** Demonstrates **encapsulation** with a `BankAccount` class that holds its own private state (`balance`, `totalPayments`) and exposes public methods (`makePayment`, `getBalance`) for interaction.
* **Separation of Concerns (Java):** The `BankAccount` class (the "engine") is separate from the `Main` class (the "runner"), which is a core OOP concept.
* **State Management:** The `makePayment` method correctly checks if funds are sufficient before modifying the account's balance.

---

## 🛠️ Technologies Used

* **C++** (specifically C++11 features)
* **Java** (built and run with OpenJDK 17)
* **Compiler/Runtime:** g++ (MinGW) for C++, Java Development Kit (JDK) for Java.

---

## 📸 Application Preview

### 1. C++ Bank Simulator (Robust Input Validation)

Here is a demonstration of the program handling incorrect user input (letters) and illogical input (negative numbers) without crashing.

```text
Initial account balance: abc
Error: Please enter a valid positive number: -100
Error: Please enter a valid positive number: 1000
Enter the interest rate (%): foo
Error: Please enter a valid positive number: 2
Enter the credit limit: 500
Enter the recurring payment amount: 800
Enter the number of months for payment: asd
Error: Please enter a valid positive integer: 3

Month 1:
---------------------------------------
Payment of 800 processed from current balance.
Balance before interest: 200
Interest applied: 4 (2%)
New balance: 204
Balance at end of month 1: 204
Remaining credit limit: 500
---------------------------------------

Month 2:
---------------------------------------
Insufficient funds! Payment cannot be processed.
Remaining credit limit: 500
Final account balance: 204

Press Enter to exit...
```

### 2. Java Bank Account (OOP Demo)

This shows the output from the Main.java class, which creates an instance of BankAccount and calls its methods.

```text
Current balance: 1000.0
Payment of 300.0 processed. New balance: 700.0
Payment of 150.0 processed. New balance: 550.0
Payment of 200.0 processed. New balance: 350.0
Insufficient funds to make payment of 500.0
Current balance: 350.0
Total payments made: 650.0
```

---

## 📂 Project Structure

```text
cs-fundamentals-cpp-java/
├── .gitignore
├── README.md                 # <-- This file
│
├── cpp-bank-simulator/
│   └── main.cpp              # Self-contained C++ application
│
└── java-bank-account/
    ├── BankAccount.java      # The BankAccount class (OOP)
    └── Main.java             # The executable Main class
```

---

## 🚀 Getting Started

### 📋 Prerequisites

To run these projects, you need the following installed on your system:

* **C++ Compiler:** g++ (via MinGW on Windows) or clang/gcc (macOS/Linux).
* **Java Development Kit (JDK):** Version 17 or higher.
* **Git:** To clone the repository.

### 🔧 Installation & Execution

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/rodel-bfr/cs-fundamentals-cpp-java.git
    cd cs-fundamentals-cpp-java
    ```

### ▶️ How to Run the C++ Bank Simulator

This requires a C++ compiler like g++ to be installed and available in your PATH.

1. **Navigate to the C++ folder:**

    ```bash
    cd cpp-bank-simulator
    ```

2. **Compile the program:**

    ```bash
    g++ main.cpp -o cpp_bank_simulator
    ```

3.  **Run the executable:**
    ```bash
    cpp_bank_simulator.exe  # On Windows
    # On macOS/Linux, use ./cpp_bank_simulator
    ```

### ▶️ How to Run the Java Bank Account Demo

This requires the Java Development Kit (JDK) to be installed and available in your PATH.

1. **Navigate to the Java folder:**

    ```bash
    cd java-bank-account
    ```

2. **Compile all .java files:**

    ```bash
    javac Main.java BankAccount.java
    ```

3.  **Run the main class:**
    ```bash
    java Main
    ```