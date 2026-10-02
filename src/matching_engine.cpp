#include "../include/matching_engine.hpp"
#include "../include/IdGeneration.hpp"
#include <algorithm>
#include <cstdint>
#include <sys/resource.h>

MatchingEngine::MatchingEngine(OrderBook* orderBook)
    :m_orderBook(orderBook)
{}

void MatchingEngine::submitOrder(Order* order)
{
    while(order->getQuantity() > 0)
    {
        if (order->getSide() == OrderSide::BUY)
        {
            Order* bestAsk = m_orderBook->bestAsk();
            if (bestAsk == nullptr)
            {
                break;
            }

            if (bestAsk->getPrice() > order->getPrice())
            {
                break;
            }

            uint64_t tradedQuantity = std::min(order->getQuantity(), bestAsk->getQuantity());

            Trade trade {
                .tradeId = generateId(),
                .buyOrderId = order->getId(),
                .sellOrderId = bestAsk->getId(),
                .price = bestAsk->getPrice(),
                .quantity = tradedQuantity
            };

            m_trades.push_back(trade);
            order->setQuanity(order->getQuantity() - tradedQuantity);
            bestAsk->setQuanity(bestAsk->getQuantity() - tradedQuantity);

            if (bestAsk->getQuantity() == 0)
            {
                m_orderBook->removeBestAsk();
            }

        }
        else if (order->getSide() == OrderSide::SELL)
        {
            Order* bestBid = m_orderBook->bestBid();
            if (bestBid == nullptr)
            {
                break;
            }

            if (bestBid->getPrice() < order->getPrice())
            {
                break;
            }

            uint64_t tradedQuantity = std::min(order->getQuantity(), bestBid->getQuantity());

            Trade trade {
                .tradeId = generateId(),
                .buyOrderId = bestBid->getId(),
                .sellOrderId = order->getId(),
                .price = bestBid->getPrice(),
                .quantity = tradedQuantity
            };

            m_trades.push_back(trade);
            order->setQuanity(order->getQuantity() - tradedQuantity);
            bestBid->setQuanity(bestBid->getQuantity() - tradedQuantity);

            if (bestBid->getQuantity() == 0)
            {
                m_orderBook->removeBestBid();
            }

        }
    }
    if (order->getQuantity() > 0)
    {
        m_orderBook->addOrder(order);
    }
}
