cmake_minimum_required(VERSION 3.20)
project(ExchangeSimulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(simulator
    src/main.cpp
    src/order.cpp
	src/IdGeneration.cpp
)
