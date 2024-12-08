#include "product.h"
#include <iostream>

Product::Product(const std::string& name, int stock, double price) 
    : name(name), stock(stock), price(price) {}

void Product::displayProduct() const {
    std::cout << "Product: " << name 
              << ", Stock: " << stock 
              << ", Price: $" << price << std::endl;
}

void Product::setStock(int stock) {
    this->stock = stock;
}

int Product::getStock() const {
    return stock;
}

std::string Product::getName() const {
    return name;
}