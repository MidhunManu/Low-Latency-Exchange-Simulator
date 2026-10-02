#pragma once

#include <cstdint>
#include <string>

enum class OrderSide
{
    BUY,
    SELL
};

enum class OrderType
{
    LIMIT,      // Buy/Sell at this price or better
    MARKET,     // Buy/Sell immediately at whatever is available.
    IOC,        // Execute immediately as much as possible; cancel whatever remains
    FOK,        // Execute the entire quantity immediately, or cancel the whole order
    POST_ONLY   // Must rest in the book; if it would immediately trade, reject/cancel it
};

using TimeStamp = uint64_t;

class Order
{
public:
    Order(OrderSide side, uint32_t price, uint64_t quantity);
    uint64_t getId() const;
    OrderSide getSide() const;
    uint32_t getPrice() const;
    uint64_t getQuantity() const;
    TimeStamp getTimeStamp() const;
    std::string toString() const;
private:
    uint64_t m_orderId;
    OrderSide m_side;
    uint32_t m_price;
    uint64_t m_quantity;
    TimeStamp m_timeStamp;
};

inline auto compareOrderAsc = [] (const Order& order1, const Order& order2)
{
    return order1.getId() > order2.getId();     
};

inline auto compareOrderDsc = [] (const Order& order1, const Order& order2)
{
    return order1.getId() < order2.getId();     
};
