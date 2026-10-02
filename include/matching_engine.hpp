#pragma once

#include "order_book.hpp"
#include "trade.hpp"
#include <vector>

class MatchingEngine
{
public:
    MatchingEngine(OrderBook* orderBook);

    void submitOrder(Order* order);

private:
    OrderBook* m_orderBook;
    std::vector<Trade> m_trades;   
};
