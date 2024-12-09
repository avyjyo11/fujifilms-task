#include <iostream>
#include "local_supplier.hpp"

void LocalSupplier::notifyRestock(int productID, int quantity) {
  std::cout << name << " notified of restock for Product ID: " 
            << productID << " with quantity: " << quantity << std::endl;
}
