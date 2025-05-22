#include "Bank.h"
#include "CustomerFactory.h"
#include <fstream>
#include <iostream>

Bank::Bank(const std::string& filename) : filename(filename) {}

void Bank::addCustomer(std::unique_ptr<Customer> customer) {
    customers.push_back(std::move(customer));
}

void Bank::loadCustomers() {
    std::ifstream in(filename);
    if (!in.is_open()) return;

    while (in.peek() != EOF) {
        auto customer = CustomerFactory::loadCustomer(in);
        if (customer) {
            customers.push_back(std::move(customer));
        }
    }
}

void Bank::saveCustomers() const {
    std::ofstream out(filename, std::ios::trunc);
    for (const auto& customer : customers) {
        customer->save(out);
    }
}

Customer* Bank::findCustomer(int id) const {
    for (const auto& customer : customers) {
        if (customer->getId() == id) return customer.get();
    }
    return nullptr;
}

bool Bank::transfer(int fromId, int toId, double amount) {
    Customer* from = findCustomer(fromId);
    Customer* to = findCustomer(toId);
    if (from && to && from->withdraw(amount)) {
        to->deposit(amount);
        return true;
    }
    return false;
}

void Bank::calculateAllInterest() {
    for (auto& customer : customers) {
        customer->calculateInterest();
    }
}

void Bank::listCustomers() const {
    for (const auto& customer : customers) {
        customer->display();
    }
}
