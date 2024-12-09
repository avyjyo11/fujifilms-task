#ifndef GLOBAL_SUPPLIER_HPP
#define GLOBAL_SUPPLIER_HPP

#include "supplier.hpp"
#include <iostream>

class GlobalSupplier : public Supplier {
public:
    GlobalSupplier(const std::string& name) : Supplier(name) {}
    void notifyRestock(int productID, int quantity) override;
};

#endif // GLOBAL_SUPPLIER_HPP