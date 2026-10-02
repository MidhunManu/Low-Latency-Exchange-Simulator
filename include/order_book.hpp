#pragma once

#include "order.hpp"
#include <map>
#include <unordered_map>
#include <deque>
#include <functional>

class OrderBook
{
public:
    void addOrder(Order* order);
    Order* bestBid() const;
    Order* bestAsk() const;
private:
    std::map<uint32_t, std::deque<Order*>, std::greater<uint32_t>> m_bids;
    std::map<uint32_t, std::deque<Order*>, std::less<uint32_t>> m_asks;
};
