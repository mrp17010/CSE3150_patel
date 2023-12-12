#ifndef ECINVENTORYMANAGER_H
#define ECINVENTORYMANAGER_H

#include "ECProduct.h"
#include <map>


class InventoryManager {
 public:
  static InventoryManager& getInstance();
  virtual ~InventoryManager() = default;

  void addProduct(Product* product, int quantity);
  void removeProduct(Product* product, int quantity);
  int getQuantity(const Product& product);
  int getQuantity(int productId);
  void reset();

 private:
  InventoryManager();
  InventoryManager(const InventoryManager&) = delete;
  void operator=(const InventoryManager&) = delete;

  std::map<int, int> inventory_;
  static InventoryManager* instanceptr;
};
#endif  // ECINVENTORYMANAGER_H
