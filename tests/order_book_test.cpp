#include <gtest/gtest.h>

#include "../include/order_book.hpp"

class OrderBookTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_orderBook = new OrderBook();

        m_order1 = new Order(
            OrderSide::SELL,
            3400,
            20);

        m_order2 = new Order(
            OrderSide::BUY,
            1000,
            20);

        m_order3 = new Order(
            OrderSide::BUY,
            1000,
            20);

        m_order4 = new Order(
            OrderSide::SELL,
            1234,
            20);
    }

    void TearDown() override
    {
        delete m_order1;
        delete m_order2;
        delete m_order3;
        delete m_order4;

        delete m_orderBook;
    }

    OrderBook* m_orderBook;

    Order* m_order1;
    Order* m_order2;
    Order* m_order3;
    Order* m_order4;
};


TEST_F(OrderBookTest, AddBuyOrder)
{
    m_orderBook->addOrder(m_order2);

    Order* bestBid = m_orderBook->bestBid();

    ASSERT_NE(bestBid, nullptr);
    EXPECT_EQ(bestBid->getPrice(), 1000);
    EXPECT_EQ(bestBid->getQuantity(), 20);
}


TEST_F(OrderBookTest, AddSellOrder)
{
    m_orderBook->addOrder(m_order1);

    Order* bestAsk = m_orderBook->bestAsk();

    ASSERT_NE(bestAsk, nullptr);
    EXPECT_EQ(bestAsk->getPrice(), 3400);
    EXPECT_EQ(bestAsk->getQuantity(), 20);
}


TEST_F(OrderBookTest, OrdersAtSamePricePreserveFIFO)
{
    m_orderBook->addOrder(m_order2);
    m_orderBook->addOrder(m_order3);

    Order* bestBid = m_orderBook->bestBid();

    ASSERT_NE(bestBid, nullptr);

    EXPECT_EQ(bestBid->getId(), m_order2->getId());
}


TEST_F(OrderBookTest, BestBidReturnsHighestPrice)
{
    m_orderBook->addOrder(m_order2); // 1000
    m_orderBook->addOrder(
        new Order(OrderSide::BUY, 1500, 20));

    Order* bestBid = m_orderBook->bestBid();

    ASSERT_NE(bestBid, nullptr);
    EXPECT_EQ(bestBid->getPrice(), 1500);
    delete bestBid;
}


TEST_F(OrderBookTest, BestAskReturnsLowestPrice)
{
    m_orderBook->addOrder(m_order1); // 3400
    m_orderBook->addOrder(m_order4); // 1234

    Order* bestAsk = m_orderBook->bestAsk();

    ASSERT_NE(bestAsk, nullptr);
    EXPECT_EQ(bestAsk->getPrice(), 1234);
}
