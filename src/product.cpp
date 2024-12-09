#include <iostream>
#include "product.hpp"

int Product::nextID = 1;

Product::Product(const std::string& name, const Category& category, double price, int stock, int threshold) : 
    productID(nextID++), productName(name), category(category), price(price), stockLevel(stock), reorderThreshold(threshold) {}

// getters
int Product::getId() const {
    return productID;
}

int Product::getStock() const {
    return stockLevel;
}

int Product::getThreshold() const {
    return reorderThreshold;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getName() const {
    return productName;
}

Category Product::getCategory() const {
    return category;
}

std::string Product::getCategoryString() const {
    return categoryToString[category];
}
// setters
void Product::setStock(int stock) {
    this->stockLevel = stock;
}

// simulate selling buy update stock
void Product::soldStock(int stock) {
    this->stockLevel = stockLevel - stock;
}

bool Product::checkRestock() const {
    if (stockLevel <= reorderThreshold) {
        return true;
    }
    return false;
}

// Utility
void Product::displayProductDetails() const {
    std::cout << "Product ID: " << productID << std::endl
              << "Product Name: " << productName << std::endl
              << "Category: " << getCategoryString() << std::endl
              << "Price: $" << price << std::endl
              << "Stock Level: " << stockLevel << std::endl
              << "Reorder Threshold: " << reorderThreshold << std::endl;
}

