#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

#include "src/product.cpp"
#include "src/supplier.cpp"
#include "src/organization.cpp"
#include "src/local_supplier.cpp"
#include "src/global_supplier.cpp"

int main(int argc, char *argv[]) {

  std::string product1 = "Television";
  std::string product2 = "Jeans";
  std::string product3 = "Cooking Pan";

  Product p1(product1, Category::Electronics, 999.99, 10, 2);
  Product p2(product2, Category::Clothing, 19.99, 30, 8);
  Product p3(product3, Category::HomeAppliances, 40.50, 20, 10);

  Organization org("DarazShop");
  org.addProduct(p1);
  org.addProduct(p2);
  org.addProduct(p3);

  LocalSupplier local_supplier("local_supplier");
  GlobalSupplier global_supplier("global_supplier");

  local_supplier.subscribeToOrganization(org);
  global_supplier.subscribeToOrganization(org);

  // Simulate a sale and update stock level
  Product* p;
  p = org.searchProductByName(product1);
  p->soldStock(9);
  p->displayProductDetails();

  p = org.searchProductByName(product2);
  p->soldStock(20);
  p->displayProductDetails();

  p = org.searchProductByName(product3);
  p->soldStock(12);
  p->displayProductDetails();

  org.generateInventoryReport();
  org.checkForRestock();
  
  return 0;
}