#include "../include/order_book.hpp"

void OrderBook::addOrder(Order* order)
{
    if (order->getSide() == OrderSide::BUY)
    {
        m_bids[order->getPrice()].push_back(order);
    }
    else
    {
        m_asks[order->getPrice()].push_back(order);
    }
}

Order* OrderBook::bestAsk() const
{
    if (m_asks.empty())
    {
        return nullptr;
    }
    return m_asks.begin()->second.front();
}

Order* OrderBook::bestBid() const
{
    if (m_bids.empty())
    {
        return nullptr;
    }
    return m_bids.begin()->second.front();
}

void OrderBook::removeBestAsk()
{
    m_asks.erase(m_asks.begin());
}

void OrderBook::removeBestBid()
{
    m_bids.erase(m_bids.begin());
}
