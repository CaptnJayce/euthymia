#include "../headers/rng.hpp"

RNG::RNG(uint64_t seed) : generator(seed) {}

float RNG::rollFloat() {
    std::uniform_real_distribution<float> dist(0, 1.0);
    return dist(generator);
}

int RNG::rollInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

float RNG::sumWeights(std::vector<ENEMY_DEF>& spawnTable) {
    float total = 0.0f;
    for (const auto& enemy : spawnTable) {
        total += enemy.spawnChance;
    }
    return total;
}