#include "../headers/tick.hpp"
#include "../headers/rng.hpp"
#include "../headers/params.hpp"
#include <iostream>

TICK::TICK(const PARAMS& params) : ticksPerSecond(params.ticksPerSecond), currentTick(0), nextTick(0), totalTicks(0) {}

int TICK::progressTick(RNG& rng) {
    for(int i = 0; i < ticksPerSecond; i++) {
        std::cout << "Tick " << i + 1 << "/" << ticksPerSecond << "\n" << std::endl;

        int n = rng.rollInt(1, 100);

        std::cout << "Random number: " << n << "\n" << std::endl;
    }
    return 0;
}

int TICK::eventQueue() {
    
    return 0;
}