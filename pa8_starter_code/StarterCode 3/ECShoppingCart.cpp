#include "ECShoppingCart.h"
#include "ECProduct.h"
using namespace std;
//shoppingcart functionality
ShoppingCart::ShoppingCart() {}

void ShoppingCart::addToCart(Product* product)
{
    items.push_back(product);
}

double ShoppingCart::getTotalPrice() const
{
    double price_total = 0.0;
    for(auto prods = items.begin(); prods!=items.end(); prods++)
    {
        price_total = price_total + (*prods)->getPrice();
    }
    return price_total;
}

void ShoppingCart::removeFromCart(Product* product)
{
    for(auto prods = items.begin(); prods!= items.end();prods++)
    {
        if(*prods == product)
        {
            items.erase(prods);
            break;
        }
    }
}
void ShoppingCart::removeFromCart(int productId)
{
    for(auto prods = items.begin(); prods!= items.end();prods++)
    {
        if((*prods)->getId() == productId)
        {
            items.erase(prods);
        }
    }
}
void ShoppingCart::clearCart()
{
    items.clear();
}

vector<Product*> ShoppingCart::getItems()
{
    return items;
}
