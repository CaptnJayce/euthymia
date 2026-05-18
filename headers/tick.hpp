#pragma once
#include "params.hpp"
#include "core.hpp"

class RNG;

class TICK {
public:
    TICK(const PARAMS& params);
    int progressTick(RNG& rng, CORE& core);    
    int getCurrentTick() const { return currentTick; }
private:
    int eventQueue();
    int ticksPerCall;
    int currentTick;
    int nextTick;
    int totalTicks;
};