#include <iostream>
#include "global_supplier.hpp"

void GlobalSupplier::notifyRestock(int productID, int quantity) {
  std::cout << name << " notified of restock for Product ID: " 
            << productID << " with quantity: " << quantity << std::endl;
}
