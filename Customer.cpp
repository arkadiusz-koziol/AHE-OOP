#include "Customer.h"

Customer::Customer() = default;

Customer::Customer(int id, const std::string& firstName, const std::string& lastName, double balance, double interestRate)
    : id(id), firstName(firstName), lastName(lastName), balance(balance), interestRate(interestRate) {}

void Customer::calculateInterest() {
    balance += balance * interestRate;
}

void Customer::display() const {
    std::cout << "ID: " << id << ", Name: " << firstName << " " << lastName
              << ", Balance: " << balance << ", Interest Rate: " << interestRate << "\n";
}

void Customer::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Customer::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

int Customer::getId() const {
    return id;
}

double Customer::getBalance() const {
    return balance;
}

std::string Customer::getType() const {
    return "Customer";
}

void Customer::save(std::ofstream& out) const {
    out << getType() << "\n" << id << "\n" << firstName << "\n" << lastName << "\n"
        << balance << "\n" << interestRate << "\n";
}

void Customer::load(std::ifstream& in) {
    std::getline(in, firstName);
    std::getline(in, lastName);
    in >> id >> balance >> interestRate;
    in.ignore();
}
