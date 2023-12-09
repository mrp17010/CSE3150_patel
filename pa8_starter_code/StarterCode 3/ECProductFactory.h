#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "ECProduct.h"

enum class ProductType { Book, Electronics, Clothing };

class ProductFactory {
 public:
  static Product* createProduct(ProductType type, int id, const std::string& name, double price,
                                const std::string& desc);
};

#endif  // PRODUCTFACTORY_H
