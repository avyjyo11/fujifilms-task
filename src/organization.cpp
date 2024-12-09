#include "organization.hpp"
#include <iostream>

Organization::Organization(const std::string& name) : name(name) {}

std::string Organization::getName() const {
    return name;
}

// Adds a new product to the inventory
void Organization::addProduct(Product& product) {
    inventory.push_back(product);
}

// Removes a product from the inventory by productID
bool Organization::removeProduct(int productID) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getId() == productID) {
            std::cout << "Removing product: " << it->getName() << " (ID: " << productID << ")" << std::endl;
            inventory.erase(it);
            return true;
        }
    }
    std::cerr << "Error: Product with ID " << productID << " not found." << std::endl;
    return false;
}

// Searches for a product by productID
Product* Organization::searchProductByID(int productID) {
    for (auto& product : inventory) {
        if (product.getId() == productID) {
            return &product;
        }
    }
    std::cerr << "Error: Product with ID " << productID << " not found." << std::endl;
    return nullptr;
}

// Searches for a product by productName
Product* Organization::searchProductByName(const std::string& productName) {
    for (auto& product : inventory) {
        if (product.getName() == productName) {
            return &product;
        }
    }
    std::cerr << "Error: Product with name '" << productName << "' not found." << std::endl;
    return nullptr;
}

// Displays the entire inventory with product details
void Organization::displayInventory() const {
    if (inventory.empty()) {
        std::cout << "The inventory is empty." << std::endl;
        return;
    }

    std::cout << "===== Organization Inventory =====" << std::endl;
    for (const auto& product : inventory) {
        std::cout << "Product ID: " << product.getId()
                  << ", Name: " << product.getName()
                  << ", Category: " << product.getCategoryString()
                  << ", Stock Level: " << product.getStock()
                  << ", Reorder Threshold: " << product.getThreshold() << std::endl;
    }
}

// Subscription to supplier
void Organization::subscribeSupplier(Supplier* supplier) {
    suppliers.push_back(supplier);
    std::cout << "Supplier subscribed successfully." << std::endl;
}

void Organization::notifySuppliers(int productID, int quantity) {
    for (Supplier* supplier : suppliers) {
        supplier->notifyRestock(productID, quantity);
    }
}

void Organization::checkForRestock() {
  for (auto& product : inventory) {
    if (product.checkRestock()) {
        int quantityNeeded = product.getThreshold() - product.getStock();
        notifySuppliers(product.getId(), quantityNeeded);
    }
  }
}

void Organization::generateInventoryReport() const {
        std::cout << "\n====================== Inventory Report ======================\n";
        
        // 1️⃣ Full List of Products
        std::cout << "\n--- Full Inventory ---\n";
        std::cout << std::setw(10) << "Product ID" 
                  << std::setw(20) << "Product Name" 
                  << std::setw(20) << "Category" 
                  << std::setw(10) << "Price" 
                  << std::setw(10) << "Stock" << std::endl;
        
        std::cout << "-------------------------------------------------------------\n";
        for (const auto& product : inventory) {
            std::cout << std::setw(10) << product.getId()
                      << std::setw(20) << product.getName()
                      << std::setw(20) << product.getCategoryString()
                      << std::setw(10) << product.getPrice()
                      << std::setw(10) << product.getStock() << std::endl;
        }

        // 2️⃣ Products Needing Restock
        std::cout << "\n--- Products Needing Restock ---\n";
        std::cout << std::setw(10) << "Product ID" 
                  << std::setw(20) << "Product Name" 
                  << std::setw(20) << "Category" 
                  << std::setw(15) << "Current Stock" 
                  << std::setw(20) << "Reorder Threshold" 
                  << std::setw(15) << "Quantity Needed" << std::endl;

        std::cout << "-------------------------------------------------------------\n";
        for (const auto& product : inventory) {
            if (product.checkRestock()) {
                int quantityNeeded = product.getThreshold() - product.getStock();
                std::cout << std::setw(10) << product.getId()
                          << std::setw(20) << product.getName()
                          << std::setw(20) << product.getCategoryString()
                          << std::setw(15) << product.getStock()
                          << std::setw(20) << product.getThreshold()
                          << std::setw(15) << quantityNeeded << std::endl;
            }
        }

        std::cout << "=============================================================\n";
    }