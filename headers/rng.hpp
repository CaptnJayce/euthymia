#pragma once
#include <random>

class RNG {
public:
    RNG(uint64_t seed);

    float rollFloat();
    int rollInt(int min, int max);
    bool rollChance(float percent);

private:
    std::mt19937_64 generator;
};