#include "../headers/tick.hpp"
#include "../headers/rng.hpp"
#include "../headers/core.hpp"
#include <iostream>

TICK::TICK(const PARAMS& params) : ticksPerCall(params.ticksPerSecond), currentTick(0), nextTick(0), totalTicks(0) {}

CORE core(const PARAMS& params);

int TICK::progressTick(RNG& rng, CORE& core) {
    for(int i = 0; i < ticksPerCall; i++) {
        currentTick++;
        std::cout << "Tick " << currentTick << "/" << ticksPerCall << std::endl;
        core.spawnEntity(rng);}
    return 0;
}

int TICK::eventQueue() {
    return 0;
}