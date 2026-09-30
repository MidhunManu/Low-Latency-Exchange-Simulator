cmake_minimum_required(VERSION 3.20)
project(ExchangeSimulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simulator
    src/main.cpp
    src/order.cpp
    src/IdGeneration.cpp
)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/order_test.cpp
    src/order.cpp
    src/IdGeneration.cpp
)

target_link_libraries(tests
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

