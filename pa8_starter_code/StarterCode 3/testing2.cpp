#include "ECCustomer.h"
#include "ECCustomerFactory.h"
#include "ECProduct.h"
#include "ECProductFactory.h"
#include "ECInventoryManager.h"
#include "ECOrder.h"
#include "ECPayment.h"
#include <iostream>

int main()
{
  CustomerFactory customerFactory;
  ProductFactory productFactory;
  PaymentMethod* paypalPayment = new PayPal(20);
  PaymentMethod* creditCardPayment = new CreditCard(0);

  // Create customers
  Customer* regular_customer =
      customerFactory.createCustomer(CustomerType::Regular, 1, "John", 700);
  Customer* premium_customer =
      customerFactory.createCustomer(CustomerType::Premium, 2, "Jane", 1000);

  std::cout << "Regular customer: " << regular_customer->getName()
            << " with loyalty points: " << regular_customer->getLoyaltyPoints() << std::endl;

  std::cout << "Premium customer: " << premium_customer->getName()
            << " with loyalty points: " << premium_customer->getLoyaltyPoints() << std::endl;

  // Create products
  Product* cpp_book = productFactory.createProduct(
      ProductType::Book, 1, "The C++ Programming Language", 49.99, "Bjarne Stroustrup");

  std::cout << "Product: " << cpp_book->getName() << " with price: " << cpp_book->getPrice()
            << " and description: " << cpp_book->getDescription() << std::endl;

  // Add products to inventory
  InventoryManager& inventoryManager = InventoryManager::getInstance();
  inventoryManager.addProduct(cpp_book, 10);

  std::cout << "Inventory of " << cpp_book->getName() << ": "
            << inventoryManager.getQuantity(*cpp_book) << std::endl;
    

    Order order1(1, regular_customer);
    std::cout<<"order: " <<order1.processOrder(creditCardPayment)<< std::endl;
    
  delete paypalPayment;
  delete creditCardPayment;
  delete cpp_book;
  delete regular_customer;
  delete premium_customer;
    
  return 0;
}