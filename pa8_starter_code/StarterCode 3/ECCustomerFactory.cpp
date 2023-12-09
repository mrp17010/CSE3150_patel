#include "ECCustomerFactory.h"

Customer* CustomerFactory::createCustomer(CustomerType type, int id, const std::string& name, int loyaltyPoints)
{
    Customer* cust;
    if (type == CustomerType::Regular)
    {
        cust = new RegularCustomer(id, name, loyaltyPoints);
    }
    if (type == CustomerType::Premium)
    {
        cust = new PremiumCustomer(id, name, loyaltyPoints);
    }
    return cust;
}
