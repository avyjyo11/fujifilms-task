#ifndef ORGANIZATION_HPP
#define ORGANIZATION_HPP

#include <string>
#include <vector>
#include "product.h"

class Organization {
private:
    std::string name;
    vector<Product> products;

public:
    Organization(const std::string& name);
    void addProduct(Product& product) const;
    std::string getName() const;
};

#endif // ORGANIZATION_HPP