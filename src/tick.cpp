#include "../headers/tick.hpp"
#include "../headers/rng.hpp"
#include <iostream>

TICK::TICK(int ticksPerSecond) : tps(ticksPerSecond) {}

int TICK::progressTick(RNG& rng) {
    for(int i = 0; i < tps; i++) {
        std::cout << "Tick " << i + 1 << "/" << tps << "\n" << std::endl;

        int n = rng.rollInt(1, 100);

        std::cout << "Random number: " << n << "\n" << std::endl;
    }
    return 0;
}