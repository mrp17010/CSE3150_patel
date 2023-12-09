#include "ECProduct.h"
#include "ECShoppingCart.h"
#include "ECCustomer.h"
#include "ECCustomerFactory.h"
#include "ECProductFactory.h"
#include <iostream>
using namespace std;
int main()
{
    CustomerFactory cfac;
    ProductFactory pfac;

    // RegularCustomer rc = RegularCustomer(1, "reg", 300);
    // PremiumCustomer pc = PremiumCustomer(2, "prem", 4002);

    Customer* rcp = cfac.createCustomer(CustomerType::Regular, 3, "factreg", 43);
    Customer* pcp = cfac.createCustomer(CustomerType::Premium, 4, "factpre", 12);

    // Product* mybook = new Book(1, "The C++ Programming Language", 49.99, "Bjarne Stroustrup");
    // Product* myelec = new Electronics(2, "laptop", 49.99, "i9");
    // Product* mycloth = new Clothing(3, "shirt", 49.99, "m");
    Product* mybook = pfac.createProduct(ProductType::Book,1, "The C++ Programming Language", 49.99, "Bjarne Stroustrup");
    Product* myelec = pfac.createProduct(ProductType::Electronics, 2, "laptop", 49.99, "i9");
    Product* mycloth = pfac.createProduct(ProductType::Clothing,3, "shirt", 49.99, "m");
    

    // rc.getShoppingCart().addToCart(mybook);
    // rc.getShoppingCart().addToCart(myelec);
    rcp->getShoppingCart().addToCart(mybook);
    rcp->getShoppingCart().addToCart(myelec);
    pcp->getShoppingCart().addToCart(mycloth);

    // cout<< rc.getId() << endl;
    // cout<< rc.getLoyaltyPoints() << endl;
    // cout<< rc.getName() << endl;
    // cout<< rc.calculateDiscount() << endl;
    // cout<< rc.getShoppingCart().getTotalPrice() << endl;

    cout <<endl;
    cout << pcp->getShoppingCart().getTotalPrice() << endl;
    cout << pcp->getShoppingCart().getItems()[0]->getDescription() << endl;
    cout << pcp->calculateDiscount() << endl;
    cout << pcp->getLoyaltyPoints() << endl;
    cout << pcp->getName() << endl;

    cout <<endl;
    cout << rcp->getShoppingCart().getTotalPrice() << endl;
    cout << rcp->getShoppingCart().getItems()[0]->getDescription() << endl;
    cout << rcp->getShoppingCart().getItems()[1]->getDescription() << endl;
    cout << rcp->calculateDiscount() << endl;
    cout << rcp->getLoyaltyPoints() << endl;
    cout << rcp->getName() << endl;
    // ShoppingCart sc = ShoppingCart();
    // sc.addToCart(mybook);
    // sc.addToCart(myelec);
    // sc.addToCart(mycloth);

    // cout << mybook->getDescription() << endl;
    // cout << myelec->getDescription() << endl;
    // cout << mycloth->getDescription() << endl;
    // cout << mybook->getName() << endl;
    // vector<Product*> scitems = sc.getItems();
    // for(auto i = scitems.begin(); i!= scitems.end(); i++)
    // {
    //     cout<< (*i)->getName() << endl;
    // }
    // cout << sc.getTotalPrice() << endl;
    // sc.removeFromCart(mybook);
    // cout<<endl;
    // cout << sc.getTotalPrice() << endl;
    delete mybook;
    delete myelec;
    delete mycloth;
    delete pcp;
    delete rcp;
    return 0;
}