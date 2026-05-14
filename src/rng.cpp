#include "../headers/rng.hpp"

RNG::RNG(uint64_t seed) : generator(seed) {}

float RNG::rollFloat() {
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(generator);
}

int RNG::rollInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

bool RNG::rollChance(float percent) {
    return rollFloat() < (percent / 100.0f);
}