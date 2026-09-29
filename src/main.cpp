#include "../include/order.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Order* order = new Order(
        OrderSide::BUY,
        1000,
        20
    );

    std::cout << order->toString();

    return 0;
}
