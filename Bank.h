#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include <memory>
#include "Customer.h"

class Bank {
private:
    std::vector<std::unique_ptr<Customer>> customers;
    std::string filename;

public:
    explicit Bank(const std::string& filename);
    void addCustomer(std::unique_ptr<Customer> customer);
    void loadCustomers();
    void saveCustomers() const;
    Customer* findCustomer(int id) const;
    bool transfer(int fromId, int toId, double amount);
    void calculateAllInterest();
    void listCustomers() const;
};

#endif
