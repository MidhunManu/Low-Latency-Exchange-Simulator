#pragma once
#include <atomic>
#include <cstdint>

extern std::atomic<uint64_t> currentGlobalstart;

struct IdRange
{
   uint64_t start;
   uint64_t end;
   uint64_t next;
};

uint32_t getNextLowerBound();

uint64_t generateId();

