#include "../include/order.hpp"
#include "../include/IdGeneration.hpp"
#include <chrono>
#include <format>

Order::Order(OrderSide side, uint32_t price, uint64_t quantity)
    :m_side(side),
	 m_price(price),
	 m_quantity(quantity),
	 m_timeStamp(std::chrono::duration_cast<std::chrono::nanoseconds>(
					 std::chrono::steady_clock::now().time_since_epoch()
					 ).count()),
	 m_orderId(generateId())
{}

std::string Order::toString() const
{
    return std::format(
        "Order<id: {} price: {} quantity: {} timestamp: {}>\n",
        m_orderId,
        m_price,
        m_quantity,
        m_timeStamp
    );
}

uint64_t Order::getId() const
{
    return m_orderId;
}

OrderSide Order::getSide() const
{
   return m_side; 
}

uint32_t Order::getPrice() const
{
    return m_price;
}

uint64_t Order::getQuantity() const
{
    return m_quantity;
}

TimeStamp Order::getTimeStamp() const
{
    return m_timeStamp;
}
