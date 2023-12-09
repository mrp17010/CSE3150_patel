#ifndef ECINVENTORYMANAGER_H
#define ECINVENTORYMANAGER_H

#include "ECProduct.h"
#include <map>


class InventoryManager {
 public:
  static InventoryManager& getInstance();
  virtual ~InventoryManager() = default;

  static void addProduct(Product* product, int quantity);
  static void removeProduct(Product* product, int quantity);
  static int getQuantity(const Product& product);
  static int getQuantity(int productId);
  static void reset();

 private:
  InventoryManager();
  InventoryManager(const InventoryManager&) = delete;
  void operator=(const InventoryManager&) = delete;

  std::map<int, int> inventory_;
};

#endif  // ECINVENTORYMANAGER_H
