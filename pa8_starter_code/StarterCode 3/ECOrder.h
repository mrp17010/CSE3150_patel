#ifndef ECORDER_H
#define ECORDER_H

#include "ECCustomer.h"
#include "ECPayment.h"

class Order 
{
 private:
  int orderId_;
  Customer* customer_;
  double totalAmount_;

 public:
  Order(int orderId, Customer* customer);
  int getOrderId() const;
  bool processOrder(PaymentMethod* paymentMethod);
};

#endif  // ECORDER_H
