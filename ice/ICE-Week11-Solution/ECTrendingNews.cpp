#include "ECTrendingNews.h"
#include <iostream>
// Your code goes here
// pay-per click subscriber

ECPayPerClickSubscriber::ECPayPerClickSubscriber(ECTrendingNews &provider) : newsProvider(provider), readCount(0) {}

void ECPayPerClickSubscriber::Update()
{
    readCount++;
}

int ECPayPerClickSubscriber::ContractCost() const
{
    return readCount; // $1 per read
}

ECContractSubscriber::ECContractSubscriber(ECTrendingNews &provider) : newsProvider(provider) {}

void ECContractSubscriber::Update()
{
}

int ECContractSubscriber::ContractCost() const
{
    return contractFee;
}

ECTrendingNews ::ECTrendingNews() : totalRevenue(0)
{
}
ECTrendingNews ::~ECTrendingNews()
{
}

// add a subscriber
void ECTrendingNews ::Subscribe(ECSubscriber *pSub)
{
    if (std::find(subscribers.begin(), subscribers.end(), pSub) == subscribers.end())
    {
        totalRevenue += pSub->ContractCost();
    }
    // subscribers.push_back(pSub);
    totalRevenue += pSub->ContractCost();
    // std::cout << "Current total revenue: " << totalRevenue << std::endl;
}
// remove a subscriber
void ECTrendingNews ::UnSubscribe(ECSubscriber *pSub)
{
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), pSub), subscribers.end());
    // std::cout << "Current total revenue: " << totalRevenue << std::endl;
}
// Notify news is available for view
void ECTrendingNews ::Notify()
{
    for (auto *subscriber : subscribers)
    {
        int preUpdateRevenue = subscriber->ContractCost();
        subscriber->Update();
        int postUpdateRevenue = subscriber->ContractCost();
        totalRevenue += (postUpdateRevenue - preUpdateRevenue);
    }
}
int ECTrendingNews::GetTotRevenue() const
{
    return totalRevenue;
}
// receive payment (assume in whole dollar)
void ECTrendingNews ::ReceivePayment(int amount)
{
}
