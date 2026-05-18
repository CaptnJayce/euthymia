#pragma once
#include "entity.hpp"
#include <random>

class RNG {
public:
    RNG(uint64_t seed);

    float rollFloat();
    int rollInt(int min, int max);
    float sumWeights(std::vector<ENEMY_DEF>& spawnTable);    

private:
    std::mt19937_64 generator;
};