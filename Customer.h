#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <memory>
#include <iostream>
#include <fstream>

class Customer {
protected:
    int id;
    std::string firstName;
    std::string lastName;
    double balance;
    double interestRate;

public:
    Customer();
    Customer(int id, const std::string& firstName, const std::string& lastName, double balance, double interestRate);
    virtual ~Customer() = default;

    virtual void calculateInterest();
    virtual void display() const;
    virtual void save(std::ofstream& out) const;
    virtual void load(std::ifstream& in);

    int getId() const;
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    virtual std::string getType() const;
};

#endif
