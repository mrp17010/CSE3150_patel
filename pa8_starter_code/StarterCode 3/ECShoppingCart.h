#ifndef ECSHOPPINGCART_H
#define ECSHOPPINGCART_H

#include <vector>
#include "ECProduct.h"

class ShoppingCart 
{
public:
  ShoppingCart();
  virtual ~ShoppingCart() = default;

  // Implement getItems which should return all items on this shopping cart 

  void addToCart(Product* product);

  double getTotalPrice() const;

  void removeFromCart(Product* product);
  void removeFromCart(int productId);
  void clearCart(); 
};

#endif  // ECSHOPPINGCART_H