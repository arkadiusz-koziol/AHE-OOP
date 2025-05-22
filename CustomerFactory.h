#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include <memory>
#include <fstream>
#include "Customer.h"
#include "CustomerVIP.h"

class CustomerFactory {
public:
    static std::unique_ptr<Customer> loadCustomer(std::ifstream& in);
};

#endif
