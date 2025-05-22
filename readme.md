# 💳 C++ Banking Application

A simple banking application written in C++ that allows you to manage customer accounts, including deposits, withdrawals, transfers, interest calculations, and persistence using text-based serialization.

---

## 🚀 Features

- Add new customers (regular or VIP)
- Deposit and withdraw funds
- Transfer between customer accounts
- Calculate interest (including VIP bonus)
- Search customers by ID
- Save/load all customers to/from a file
- Command-line user interface (text-based)

---

## 🏗️ Project Structure

/bank-app
│
├── src/
│ ├── main.cpp
│ ├── Bank.cpp / Bank.h
│ ├── Customer.cpp / Customer.h
│ ├── CustomerVIP.cpp / CustomerVIP.h
│ ├── CustomerFactory.cpp / CustomerFactory.h
│
├── customers.dat
├── README.md

---

## 🧰 Requirements

- C++17 or later
- Any modern C++ compiler (G++, Clang, MSVC)

---

## 🛠️ Build Instructions

### Using `g++` manually:

```bash
g++ -std=c++17 -o projekt-oop src/*.cpp
./projekt-oop