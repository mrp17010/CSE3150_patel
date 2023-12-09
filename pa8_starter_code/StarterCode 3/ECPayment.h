#ifndef ECPAYMENT_H
#define ECPAYMENT_H

// enum class PaymentMethod { CreditCard, PayPal };
class PaymentMethod {
 public:
  virtual bool charge(double amount) = 0;
  virtual double getBalance() const = 0;
  virtual ~PaymentMethod() {}
};

// Implement derived classes CreditCard and PayPal
// Derived classes should provide an implmenetation for charge and getBalance to be able to instantiate the class 


#endif  // ECPAYMENT_H
