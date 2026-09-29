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
    std::string toString() const;
private:
    uint64_t m_orderId;
    OrderSide m_side;
    uint32_t m_price;
    uint64_t m_quantity;
    TimeStamp m_timeStamp;
};