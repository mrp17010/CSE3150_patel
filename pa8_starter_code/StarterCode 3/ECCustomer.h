#ifndef ECCUSTOMER_H
#define ECCUSTOMER_H

#include "ECShoppingCart.h"
#include <string>

class Customer 
{
public:
  Customer(int id, const std::string& name, int loyaltyPoints);
  virtual ~Customer() = default;

  int getId() const;
  std::string getName() const;
  int getLoyaltyPoints() const;

  ShoppingCart& getShoppingCart();

  virtual double calculateDiscount() const = 0;

protected:
  int id_;
  std::string name_;
  int loyaltyPoints_;
  ShoppingCart cart_;
};

// Implement derived classes RegularCustomer and PremiumCustomer
// Derived classes should provide an implmenetation for calculateDiscount to be able to instantiate the class  

#endif  // ECCUSTOMER_H
