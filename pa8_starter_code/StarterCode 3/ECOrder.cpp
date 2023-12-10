#include "ECOrder.h"
#include "ECInventoryManager.h"
#include <map>
#include <stdexcept>
using namespace std;

Order::Order(int orderId, Customer* customer): orderId_(orderId), customer_(customer)
{totalAmount_ = customer_->getShoppingCart().getTotalPrice();}

int Order::getOrderId() const{
    return orderId_;
}
bool Order::processOrder(PaymentMethod* paymentMethod)
{
    try
    {
        InventoryManager& inv = InventoryManager::getInstance();
        //get products and quantities from shopping cart, put into map
        map<Product*, int> prods;
        vector<Product*> cart_items = customer_->getShoppingCart().getItems();
        if(customer_->getShoppingCart().getItems().empty())
        {return true;}
        for(auto in_cart = cart_items.begin(); in_cart != cart_items.end(); in_cart++)
        {
            prods[(*in_cart)] += 1;
        }
        //checks: are there enough items in inventory? do you have enough money?
        //payment won't even go through if there isn't enough money
        //so just buy and see if the charge comes back positive
        
        //have to check if there are enough items first before removing. 
        for(auto to_buy = prods.begin(); to_buy != prods.end(); to_buy++)
        {
            //not enough items
            if(inv.getQuantity(*(to_buy->first)) < to_buy->second)
            {
                return false;
            }
        }
        // enough items do exist, now charge
        double discount = 100. - customer_->calculateDiscount();
        double to_charge = totalAmount_ * (.01*discount);
        bool payment_succ = paymentMethod->charge(to_charge);
        if(payment_succ == false)
        {
            return false;
        }
        // payment went through, supply goods
        for(auto to_buy = prods.begin(); to_buy != prods.end(); to_buy++)
        {
            inv.removeProduct(to_buy->first, to_buy->second);
        }
        return true;

    }
    catch(const exception& ex)
    {
        return false;
    }
}
