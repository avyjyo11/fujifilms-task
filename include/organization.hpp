#ifndef ORGANIZATION_HPP
#define ORGANIZATION_HPP

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "product.hpp"
#include "supplier.hpp"

class Supplier;

class Organization {
private:
    std::string name;
    std::vector<Product> inventory;
    std::vector<Supplier*> suppliers;

public:
    Organization(const std::string& name);
    std::string getName() const;

    void addProduct(Product& product);
    bool removeProduct(int productID);

    Product* searchProductByID(int productID);
    Product* searchProductByName(const std::string& productName);

    void displayInventory() const;

    // methods for supplier subscription and notification
    void subscribeSupplier(Supplier* supplier);
    void notifySuppliers(int productID, int quantity);
    void checkForRestock();
    
    void generateInventoryReport() const;
};

#endif // ORGANIZATION_HPP