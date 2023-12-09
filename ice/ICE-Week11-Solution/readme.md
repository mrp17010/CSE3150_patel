
# Observer Pattern Implementation

## TrendingNews.inc - Online News Provider

### Classes to Implement

1. **ECTrendingNews**
   - Role: News provider.
   - Responsibilities:
     - Keeps track of subscribers.
     - Provides news updates.
     - Tracks revenue.

2. **ECSubscriber**
   - Role: Generic subscriber to the news.

3. **ECPayPerClickSubscriber**
   - Role: Pay-per-click subscriber.
   - Characteristics:
     - Pays a fixed fee ($1 per read).

4. **ECContractSubscriber**
   - Role: Annual contract subscriber.
   - Characteristics:
     - Pays an annual fee of $100.

### Assumptions and Rules

- The evaluation period is limited to one year.
- No refunds are provided for canceled subscriptions.
- The annual fee is charged for all contract subscribers regardless of prior payments within the year.


