#include "ECCustomer.h"
#include "ECCustomerFactory.h"
#include "ECProduct.h"
#include "ECProductFactory.h"
#include "ECInventoryManager.h"
#include "ECOrder.h"
#include "ECPayment.h"
#include <iostream>

int main() {
  CustomerFactory customerFactory;
  ProductFactory productFactory;

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

  // Adding products to customers' carts
  regular_customer->getShoppingCart().addToCart(cpp_book);
  regular_customer->getShoppingCart().addToCart(cpp_book);
  regular_customer->getShoppingCart().addToCart(cpp_book);

  premium_customer->getShoppingCart().addToCart(cpp_book);
  premium_customer->getShoppingCart().addToCart(cpp_book);
  premium_customer->getShoppingCart().addToCart(cpp_book);
  premium_customer->getShoppingCart().addToCart(cpp_book);
  premium_customer->getShoppingCart().addToCart(cpp_book);
  premium_customer->getShoppingCart().addToCart(cpp_book);

  std::cout << regular_customer->getName() << "'s cart contains "
            << regular_customer->getShoppingCart().getItems().size() << " items."
            << " Total price: " << regular_customer->getShoppingCart().getTotalPrice()
            << " with discount: " << regular_customer->calculateDiscount() << "%" << std::endl;

  std::cout << premium_customer->getName() << "'s cart contains "
            << premium_customer->getShoppingCart().getItems().size() << " items."
            << " Total price: " << premium_customer->getShoppingCart().getTotalPrice()
            << " with discount: " << premium_customer->calculateDiscount() << "%" << std::endl;

  // Create payment methods
  PaymentMethod* paypalPayment = new PayPal(20);
  PaymentMethod* creditCardPayment = new CreditCard(0);

  std::cout << "PayPal init. balance: " << paypalPayment->getBalance() << std::endl;
  std::cout << "Credit card init. balance: " << creditCardPayment->getBalance() << std::endl;

  // insufficient balance in PayPal
  Order order1(1, regular_customer);
  if (order1.processOrder(paypalPayment)) {
    std::cout << "Order 1 processed successfully." << std::endl;
  } else {
    std::cout << "Order 1 processing failed." << std::endl;
  }

  // Sufficient balance in credit card
  Order order2(2, premium_customer);
  if (order2.processOrder(creditCardPayment)) {
    std::cout << "Order 2 processed successfully." << std::endl;
  } else {
    std::cout << "Order 2 processing failed." << std::endl;
  }

  // check payment method balances
  std::cout << "PayPal balance: " << paypalPayment->getBalance() << std::endl;
  std::cout << "Credit card balance: " << creditCardPayment->getBalance() << std::endl;

  // Display inventory
  std::cout << "Inventory of " << cpp_book->getName() << ": "
            << inventoryManager.getQuantity(*cpp_book) << std::endl;

  // Clean up
  delete paypalPayment;
  delete creditCardPayment;
  delete cpp_book;
  delete regular_customer;
  delete premium_customer;

  return 0;
}
