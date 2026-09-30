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
    LIMIT
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