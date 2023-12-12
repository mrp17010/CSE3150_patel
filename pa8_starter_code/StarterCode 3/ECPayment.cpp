#include "ECPayment.h"

CreditCard::CreditCard(): balance(0.0){}
CreditCard::CreditCard(double init_bal): balance(init_bal) {}
CreditCard::~CreditCard() {}
bool CreditCard::charge(double amount)
{
    balance -= amount;
    return true;
}
double CreditCard::getBalance() const
{
    return balance;
}

PayPal::PayPal(): balance(0.0){}
PayPal::PayPal(double init_bal): balance(init_bal) {}
PayPal::~PayPal(){}
bool PayPal::charge(double amount)
{
    if (balance-amount < 0)
    {
        return false;
    }
    else
    {
        balance -= amount;
        return true;
    }
}
double PayPal::getBalance() const
{
    return balance;
}