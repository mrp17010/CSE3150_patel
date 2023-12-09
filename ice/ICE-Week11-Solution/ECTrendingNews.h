#ifndef EC_TRANDING_NEWS_H
#define EC_TRANDING_NEWS_H

#include <vector>

class ECTrendingNews;

// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
	virtual void Update() = 0;
	virtual int ContractCost() const = 0;
};

// pay-per click subscriber
class ECPayPerClickSubscriber : public ECSubscriber
{
private:
	int readCount;
	ECTrendingNews &newsProvider;

public:
	ECPayPerClickSubscriber(ECTrendingNews &provider);
	virtual void Update() override;
	virtual int ContractCost() const override;
};

class ECContractSubscriber : public ECSubscriber
{
private:
	static const int contractFee = 100;
	ECTrendingNews &newsProvider;

public:
	ECContractSubscriber(ECTrendingNews &provider);
	virtual void Update() override;
	virtual int ContractCost() const override;
};

// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews();
	~ECTrendingNews();
	// add a subscriber
	void Subscribe(ECSubscriber *pSub);
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub);
	// Notify news is available for view
	void Notify();
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount);
	// Get total revenue received
	int GetTotRevenue() const;

private:
	std::vector<ECSubscriber *> subscribers;
	int totalRevenue;
};

#endif
