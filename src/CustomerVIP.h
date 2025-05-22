#ifndef CUSTOMERVIP_H
#define CUSTOMERVIP_H

#include "Customer.h"

class CustomerVIP : public Customer {
private:
    double additionalInterestRate;

public:
    CustomerVIP();
    CustomerVIP(int id, const std::string& firstName, const std::string& lastName, double balance, double interestRate, double additionalInterestRate);

    void calculateInterest() override;
    void display() const override;
    std::string getType() const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
};

#endif
