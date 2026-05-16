#pragma once
#include "rng.hpp"

class TICK {
public:
    TICK(int ticksPerSecond);
    int progressTick(RNG& rng);    

private:
    int tps;
};