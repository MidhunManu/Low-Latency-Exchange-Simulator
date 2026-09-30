#include <gtest/gtest.h>
#include "../include/order.hpp"

class OrderTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        order = new Order(
            OrderSide::BUY,
            1000,
            20);
    }

    void TearDown() override
    {
        delete order;
    }

    Order *order;
};

TEST_F(OrderTest, CreateCorrectOrderSide) { ASSERT_EQ(order->getSide(), OrderSide::BUY);}

TEST_F(OrderTest, CreateCorrectOrderType) { ASSERT_EQ(order->getSide(), OrderSide::BUY); }

TEST_F(OrderTest, CreateCorrectPrice) { ASSERT_EQ(order->getPrice(), 1000); }

TEST_F(OrderTest, CreateCorrectQuantity) { ASSERT_EQ(order->getQuantity(), 20); }

TEST_F(OrderTest, GenerateOrderID) { ASSERT_NE(order->getId(), 0); }

TEST_F(OrderTest, GenerateTimestamp) { ASSERT_NE(order->getTimeStamp(), 0); }

TEST_F(OrderTest, GenerateUniqueTimeStamp)
{
    Order* secondOrder = new Order {
        OrderSide::SELL,
        400,
        5000
    };

    ASSERT_NE(order->getId(), secondOrder->getId());
}
