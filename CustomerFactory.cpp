#include "CustomerFactory.h"

std::unique_ptr<Customer> CustomerFactory::loadCustomer(std::ifstream& in) {
    std::string type;
    std::getline(in, type);

    std::unique_ptr<Customer> customer;

    if (type == "CustomerVIP") {
        customer = std::make_unique<CustomerVIP>();
    } else {
        customer = std::make_unique<Customer>();
    }

    customer->load(in);
    return customer;
}
