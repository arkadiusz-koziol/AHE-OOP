#include "CustomerVIP.h"

CustomerVIP::CustomerVIP() = default;

CustomerVIP::CustomerVIP(int id, const std::string& firstName, const std::string& lastName,
                         double balance, double interestRate, double additionalInterestRate)
    : Customer(id, firstName, lastName, balance, interestRate), additionalInterestRate(additionalInterestRate) {}

void CustomerVIP::calculateInterest() {
    balance += balance * (interestRate + additionalInterestRate);
}

void CustomerVIP::display() const {
    std::cout << "ID: " << id << " (VIP), Name: " << firstName << " " << lastName
              << ", Balance: " << balance << ", Interest Rate: " << interestRate
              << ", Additional VIP: " << additionalInterestRate << "\n";
}

std::string CustomerVIP::getType() const {
    return "CustomerVIP";
}

void CustomerVIP::save(std::ofstream& out) const {
    out << getType() << "\n" << id << "\n" << firstName << "\n" << lastName << "\n"
        << balance << "\n" << interestRate << "\n" << additionalInterestRate << "\n";
}

void CustomerVIP::load(std::ifstream& in) {
    std::getline(in, firstName);
    std::getline(in, lastName);
    in >> id >> balance >> interestRate >> additionalInterestRate;
    in.ignore();
}
