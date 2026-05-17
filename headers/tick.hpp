#pragma once
#include "params.hpp"

class RNG;

class TICK {
public:
    TICK(const PARAMS& params);
    int progressTick(RNG& rng);    
    int currentTick;
private:
    int eventQueue();
    int ticksPerSecond;
    int nextTick;
    int totalTicks;
};