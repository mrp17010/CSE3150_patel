#ifndef ECPAYMENT_H
#define ECPAYMENT_H

// enum class PaymentMethod { CreditCard, PayPal };
class PaymentMethod {
 public:
  virtual bool charge(double amount) = 0;
  virtual double getBalance() const = 0;
  virtual ~PaymentMethod() {};
};

// Implement derived classes CreditCard and PayPal
// Derived classes should provide an implmenetation for charge and getBalance to be able to instantiate the class 

class CreditCard: public PaymentMethod
{
  public:
    CreditCard();
    CreditCard(double init_bal);
    ~CreditCard();
    bool charge(double amount) override;
    double getBalance() const override;
  private:
    double balance;
};

class PayPal: public PaymentMethod
{
  public:
    PayPal();
    PayPal(double init_bal);
    ~PayPal();
    bool charge(double amount) override;
    double getBalance() const override;
  private:
    double balance; 
};

#endif  // ECPAYMENT_H
