#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    std::string name;
    int stock;
    double price;

public:
    Product(const std::string& name, int stock, double price);
    void displayProduct() const;
    void setStock(int stock);
    int getStock() const;
    std::string getName() const;
};

#endif // PRODUCT_HPP