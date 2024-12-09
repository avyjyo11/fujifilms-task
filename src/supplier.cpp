#include "supplier.hpp"
#include "organization.hpp"

Supplier::Supplier(const std::string& name) : name(name) {}

void Supplier::subscribeToOrganization(Organization& org) {
    org.subscribeSupplier(this);
}