#ifndef ECCUSTOMERFACTORY_H
#define ECCUSTOMERFACTORY_H

#include "ECCustomer.h"

enum class CustomerType { Regular, Premium };

class CustomerFactory {
 public:
  static Customer* createCustomer(CustomerType type, int id, const std::string& name,
                                  int loyaltyPoints);
};

#endif  // ECCUSTOMERFACTORY_H
