#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include <string>
#include "organization.hpp"

// Forward declaration to avoid circular dependency
class Organization;

class Supplier {
protected:
  std::string name;
public:
  Supplier(const std::string& name);
  virtual ~Supplier() = default; // Virtual destructor for base class

  virtual void notifyRestock(int productID, int quantity) = 0; // Pure virtual function
  void subscribeToOrganization(Organization& org); // Subscribe supplier to organization
};

#endif // SUPPLIER_HPP