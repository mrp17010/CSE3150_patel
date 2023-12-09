#include "ECProductFactory.h"

Product* ProductFactory::createProduct(ProductType type, int id, const std::string& name, double price, const std::string& desc)
{
    Product* prod;
    if (type == ProductType::Electronics)
    {
        prod = new Electronics(id, name, price, desc);
    }
    if (type == ProductType::Book)
    {
        prod = new Book(id, name, price, desc);

    }    
    if (type == ProductType::Clothing)
    {
        prod = new Clothing(id, name, price, desc);
    }
    return prod;
}
