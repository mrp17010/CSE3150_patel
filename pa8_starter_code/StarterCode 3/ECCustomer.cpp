#include "ECCustomer.h"
using namespace std;

//customer functionality

Customer::Customer(int id, const string& name, int loyaltyPoints): id_(id), name_(name), loyaltyPoints_(loyaltyPoints) {cart_ = ShoppingCart();}
int Customer::getId() const{
    return id_;
}
string Customer::getName() const{
    return name_;
}
int Customer::getLoyaltyPoints() const{
    return loyaltyPoints_;
}

ShoppingCart& Customer::getShoppingCart()
{
    return cart_;
}

//regular customer functionality

RegularCustomer::RegularCustomer(int id, const string& name, int loyaltyPoints):Customer(id, name, loyaltyPoints){}
RegularCustomer::~RegularCustomer(){}
double RegularCustomer::calculateDiscount() const
{
    if(loyaltyPoints_>100)
    {
        return 10.0;
    }
    else
    {
        return 0.0;
    }
}

PremiumCustomer::PremiumCustomer(int id, const string& name, int loyaltyPoints):Customer(id, name, loyaltyPoints){}
PremiumCustomer::~PremiumCustomer(){}
double PremiumCustomer::calculateDiscount() const
{
    if(loyaltyPoints_>100)
    {
        return 20.0;
    }
    else
    {
        return 0.0;
    }   
}
