#include "../headers/rng.hpp"
#include "../headers/tick.hpp"
#include "../headers/params.hpp"
#include <iostream>

int main() {
    PARAMS params;
    params.framesPerSecond = 60;
    params.ticksPerSecond = 5;
    params.totalLevels = 3;

    uint64_t seed;

    std::cout << "Type a seed: ";
    std::cin >> seed;

    RNG rng(seed);

    for(int i = 0; i < params.totalLevels; i++) {
        std::cout << i << "\n";

        TICK tick(params);
        tick.progressTick(rng);
    }

    return 0;
}