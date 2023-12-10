#include "ECInventoryManager.h"
#include <stdexcept>
using namespace std;

InventoryManager* InventoryManager::instanceptr = nullptr;
InventoryManager::InventoryManager(){}
void InventoryManager::addProduct(Product* product, int quantity)
{
    int id = product->getId();
    auto item = inventory_.find(id);
    if (item == inventory_.end())
    {
        inventory_[id] = quantity;
    }
    else
    {
        item->second = (item->second+quantity);
    }
}
void InventoryManager::removeProduct(Product* product, int quantity)
{
    int id = product->getId();
    auto item = inventory_.find(id);
    if (item == inventory_.end())
    {
        throw runtime_error("Item not in inventory");
    }
    else
    {
        int item_quant = item->second;
        if (quantity>item_quant)
        {
            throw runtime_error("Not enough items in");
        }
        item->second = (item_quant-quantity);
    }
}
int InventoryManager::getQuantity(const Product& product)
{

    int id = product.getId();
    int quantity = inventory_.at(id);
    return quantity;
}
int InventoryManager::getQuantity(int productId)
{

    int quantity = inventory_.at(productId);
    return quantity;
}
void InventoryManager::reset()
{
    inventory_.clear();
}
InventoryManager& InventoryManager::getInstance()
{
    if(!instanceptr)
    {
        instanceptr = new InventoryManager();
    }
    return *instanceptr;
}