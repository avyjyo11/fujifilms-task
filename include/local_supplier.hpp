#ifndef LOCAL_SUPPLIER_HPP
#define LOCAL_SUPPLIER_HPP

#include "supplier.hpp"
#include <iostream>

class LocalSupplier : public Supplier {
public:
    LocalSupplier(const std::string& name) : Supplier(name) {}
    void notifyRestock(int productID, int quantity) override;
};

#endif // LOCAL_SUPPLIER_HPP