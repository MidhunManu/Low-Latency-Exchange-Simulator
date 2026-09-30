#include "../include/IdGeneration.hpp"

std::atomic<uint64_t> currentGlobalstart(0);

uint32_t getNextLowerBound()
{
    return currentGlobalstart.fetch_add(1024);
}

uint64_t generateId()
{
    IdRange range {};
    range.start = getNextLowerBound();
    range.end = range.end + 1024;
    range.next = range.start + 1;

    return range.next++;
}

