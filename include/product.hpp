#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <map>


enum class Category : uint8_t
{
    Clothing,
    Electronics,
    HomeAppliances
};

std::map<Category, std::string> categoryToString = {
  { Category::Clothing, "Clothing" },
  { Category::Electronics, "Electronics" },
  { Category::HomeAppliances, "HomeAppliances" }
};

class Product {
private:
    static int nextID; 
    int productID;
    std::string productName;
    Category category;
    double price;
    int stockLevel;
    int reorderThreshold;

public:
    Product(const std::string& name, const Category& category, double price, int stock, int threshold);

    int getId() const;

    int getStock() const;

    int getThreshold() const;

    double getPrice() const;

    std::string getName() const;

    Category getCategory() const;

    std::string getCategoryString() const;

    void setStock(int stock);

    void soldStock(int stock);

    bool checkRestock() const;

    void displayProductDetails() const;
};

#endif // PRODUCT_HPP